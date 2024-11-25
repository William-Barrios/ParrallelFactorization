#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cuda_runtime.h>
#include <climits> // Para INT_MAX

struct Supernodo {
    int id;
    int rows;
    int cols;
};

void leerSupernodos(const std::string& archivo, std::vector<Supernodo>& supernodos) {
    std::ifstream file(archivo);
    if (!file.is_open()) {
        std::cerr << "Error al abrir el archivo: " << archivo << std::endl;
        return;
    }

    std::string linea;
    while (std::getline(file, linea)) {
        std::istringstream iss(linea);
        std::string temp;
        Supernodo supernodo;

        // Parsear la línea
        iss >> temp >> supernodo.id >> temp >> supernodo.rows >> temp >> temp >> supernodo.cols;
        supernodos.push_back(supernodo);
    }
    file.close();
}

int calcularSupernodos(const std::vector<Supernodo>& supernodos, double gpuMemBytes, double porcentajeMem, double porcentajeSupernodos) {
    double maxMemUso = gpuMemBytes * porcentajeMem; // Máximo uso de memoria permitido
    int maxSupernodos = static_cast<int>(supernodos.size() * porcentajeSupernodos); // Máximo número de supernodos

    //std::cout << "Memoria máxima permitida: " << maxMemUso << " bytes\n";
    //std::cout << "Número máximo de supernodos permitidos: " << maxSupernodos << "\n";

    double memoriaUsada = 0.0;
    int supernodosSeleccionados = 0;
    int minTamanoSupernodo = INT_MAX; // Inicializar con un valor grande

    // Recorrer la lista en sentido inverso
    for (int i = supernodos.size() - 1; i >= 0; --i) {
        const auto& supernodo = supernodos[i];

        // Calcular la memoria ocupada por el supernodo
        double memoriaSupernodo = static_cast<double>(supernodo.rows) * supernodo.rows * sizeof(double);
        

        // Verificar restricciones
        if (memoriaUsada + memoriaSupernodo > maxMemUso) {
            break;
        }
        if (supernodosSeleccionados + 1 > maxSupernodos) {
            //std::cout << "-> No seleccionado: excede el número máximo de supernodos.\n";
           break;
        }

        // Actualizar el tamaño del supernodo más pequeño seleccionado
        int tamanoActual = supernodo.rows * supernodo.rows;
        if (tamanoActual < minTamanoSupernodo) {
            minTamanoSupernodo = tamanoActual;
        }

        // Agregar supernodo
        memoriaUsada += memoriaSupernodo;
        supernodosSeleccionados++;
        std::cout << "Procesando Supernodo " << supernodo.id
                << " (" << supernodo.rows << "x" << supernodo.cols
                << "), Memoria requerida: " << memoriaSupernodo << " bytes\n";
        std::cout << "-> Seleccionado. Memoria acumulada: " << memoriaUsada << " bytes\n";
    }   

    if (supernodosSeleccionados == 0) {
        //std::cout << "No se seleccionó ningún supernodo debido a las restricciones.\n";
    }
    //std::cout << "Memoria acumulada: " << memoriaUsada << " bytes\n";

    return minTamanoSupernodo;
}

double obtenerMemoriaGPUDinamica() {
    size_t free_mem = 0, total_mem = 0;
    if (cudaMemGetInfo(&free_mem, &total_mem) != cudaSuccess) {
        std::cerr << "Error al obtener información de la memoria de la GPU.\n";
        return 0.0;
    }
    return static_cast<double>(total_mem);
}

int main() {
    const std::string archivoSupernodos = "supernodo_sizes.txt";
    const double porcentajeMem = 0.04;  
    const double porcentajeSupernodos = 0.05; 

    // Obtener memoria de la GPU dinámicamente
    double gpuMemBytes = obtenerMemoriaGPUDinamica();
    if (gpuMemBytes <= 0) {
        std::cerr << "No se pudo obtener la memoria total de la GPU.\n";
        return 1;
    }
    std::cout << "Memoria total de la GPU: " << gpuMemBytes << " bytes\n";

    std::vector<Supernodo> supernodos;
    leerSupernodos(archivoSupernodos, supernodos);

    if (supernodos.empty()) {
        std::cerr << "No se encontraron datos de supernodos en el archivo.\n";
        return 1;
    }

    int minTamanoSupernodo = calcularSupernodos(supernodos, gpuMemBytes, porcentajeMem, porcentajeSupernodos);

    if (minTamanoSupernodo == INT_MAX) {
        std::cout << "No se seleccionó ningún supernodo.\n";
    } else {
        std::cout << "Tamaño del supernodo más pequeño seleccionado: " << minTamanoSupernodo << " (filas * columnas)\n";
    }

    
    // Al final de tu función main:
    std::ofstream outFile("min_supernodo.txt");
    if (outFile.is_open()) {
        outFile << minTamanoSupernodo << std::endl;
        outFile.close();
    } else {
        std::cerr << "Error al escribir en el archivo min_supernodo.txt" << std::endl;
    }


    return 0;
}