#!/bin/bash

# Configuración inicial
EXECUTABLE="/home/william/sympack/upcxx-2023.9.0/bin/upcxx-run"
APP="./run_sympack2D"
INPUT_FILE="boneS10/boneS10.rb"  # Aquí puedes poner el nombre de la matriz, o un path completo
ORDERING="MMD"
NRHS=1
GPU_V="-gpu_v"
GPU_MEM="-gpu_mem 1.5G"
GPU_BLK="-gpu_blk 1048576"
SHARED_HEAP="4G"
NP=4  # Valor por defecto de nodos

# Verifica si se proporcionó un path personalizado para la matriz, sino, usa el valor predeterminado
if [ -z "$1" ]; then
    echo "No matrix file provided, using default: $INPUT_FILE"
else
    INPUT_FILE=$1  # Asigna el path de la matriz si se pasa como primer argumento
    echo "Using provided matrix file: $INPUT_FILE"
fi

# Verifica si se proporcionó un número de nodos personalizado, sino, usa el valor predeterminado
if [ -z "$2" ]; then
    echo "No number of nodes provided, using default: $NP"
else
    NP=$2  # Asigna el número de nodos si se pasa como segundo argumento
    echo "Using provided number of nodes: $NP"
fi

# Ejecuta el comando base
echo "Running base command..."
$EXECUTABLE -n $NP -shared-heap $SHARED_HEAP -- $APP -in $INPUT_FILE -ordering $ORDERING -nrhs $NRHS $GPU_V $GPU_MEM $GPU_BLK
if [ $? -ne 0 ]; then
    echo "Base command failed. Exiting."
    exit 1
fi

# Generar valores usando threshold.cpp
THRESHOLD_CALCULATOR="./threshold"
if [ ! -f $THRESHOLD_CALCULATOR ]; then
    echo "Threshold calculator ($THRESHOLD_CALCULATOR) not found. Compile threshold.cpp first."
    exit 1
fi

# Ejecuta threshold para calcular el umbral
echo "Running threshold calculation..."
$THRESHOLD_CALCULATOR
if [ $? -ne 0 ]; then
    echo "Threshold calculation failed. Exiting."
    exit 1
fi

# Leer el tamaño mínimo seleccionado desde el archivo min_supernodo.txt
MIN_SUPERNODO=$(cat min_supernodo.txt)
if [ -z "$MIN_SUPERNODO" ]; then
    echo "No se pudo leer el tamaño mínimo de supernodo desde min_supernodo.txt. Exiting."
    exit 1
fi
echo "Tamaño mínimo de supernodo: $MIN_SUPERNODO"

# Ejecutar el comando con todos los límites
echo "Running command with all limits set to threshold value..."
$EXECUTABLE -n $NP -shared-heap $SHARED_HEAP -- $APP -in $INPUT_FILE -ordering $ORDERING -nrhs $NRHS $GPU_V $GPU_MEM $GPU_BLK -trsm_limit $MIN_SUPERNODO -potrf_limit $MIN_SUPERNODO -gemm_limit $MIN_SUPERNODO -syrk_limit $MIN_SUPERNODO

# Verifica si el comando tuvo éxito
if [ $? -ne 0 ]; then
    echo "Command with all limits set to $MIN_SUPERNODO failed. Exiting."
    exit 1
fi

echo "Command completed successfully."
