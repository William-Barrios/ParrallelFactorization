#ifndef _UPCXX_CONFIG_HPP
#define _UPCXX_CONFIG_HPP 1

#define UPCXX_NETWORK_IBV 1
#define UPCXXI_MPSC_QUEUE_ATOMIC 1
#undef  UPCXXI_DISCONTIG
#undef  UPCXXI_FORCE_LEGACY_RELOCATIONS
#define UPCXXI_CONFIGURE_ARGS "--prefix=home/william/sympack/upcxx-2023.9.0 --enable-cuda"
#define UPCXXI_HAVE___BUILTIN_ASSUME_ALIGNED 1
#define UPCXXI_HAVE___BUILTIN_LAUNDER 1
#define UPCXXI_HAVE___CXA_DEMANGLE 1
#define UPCXXI_ATTRIB_NOINLINE __attribute__((__noinline__)) 
#if defined(HIP_INCLUDE_HIP_AMD_DETAIL_HOST_DEFINES_H) && defined(__noinline__)
  /* issue 550: workaround ROCm HIP headers breaking the GNU __noinline__ attribute */
  #undef  UPCXXI_ATTRIB_NOINLINE
  #define UPCXXI_ATTRIB_NOINLINE
#endif
#define UPCXXI_ATTRIB_NORETURN __attribute__((__noreturn__))
#define UPCXXI_ATTRIB_PURE __attribute__((__pure__))
#define UPCXXI_ATTRIB_CONST __attribute__((__const__))
#define UPCXXI_MAXEPS 33 
#define UPCXXI_GEX_MK_CUDA 1 
#undef UPCXXI_GEX_MK_HIP // GASNET_HAVE_MK_CLASS_HIP not defined
#undef UPCXXI_GEX_MK_ZE // GASNET_HAVE_MK_CLASS_ZE not defined
#define UPCXXI_NATIVE_NP_ALLOC_REQ_MEDIUM 1 
#define UPCXXI_SPINLOOP_HINT() __asm__ __volatile__ ("pause" : : : "memory")
#define UPCXXI_UNREACHABLE() __builtin_unreachable()
#define UPCXXI_PREDICT_TRUE(expr) (!__builtin_expect( (!(uintptr_t)(expr)), 0 ))
#define UPCXXI_PREDICT_FALSE(expr) ( __builtin_expect( ( (uintptr_t)(expr)), 0 ))
#define UPCXXI_ASSUME(expr) ((!__builtin_expect( (!(uintptr_t)(expr)), 0 )) ? (void)0 : (__builtin_unreachable(),((void)0)))
#define UPCXXI_PLATFORM_ARCH_X86_64 1 
#undef UPCXXI_PLATFORM_ARCH_POWERPC // PLATFORM_ARCH_POWERPC not defined
#undef UPCXXI_PLATFORM_ARCH_AARCH64 // PLATFORM_ARCH_AARCH64 not defined
#undef UPCXXI_PLATFORM_ARCH_BIG_ENDIAN // PLATFORM_ARCH_BIG_ENDIAN not defined
#define UPCXXI_PLATFORM_OS_LINUX 1 
#undef UPCXXI_PLATFORM_OS_FREEBSD // PLATFORM_OS_FREEBSD not defined
#undef UPCXXI_PLATFORM_OS_NETBSD // PLATFORM_OS_NETBSD not defined
#undef UPCXXI_PLATFORM_OS_OPENBSD // PLATFORM_OS_OPENBSD not defined
#undef UPCXXI_PLATFORM_OS_DARWIN // PLATFORM_OS_DARWIN not defined
#undef UPCXXI_PLATFORM_OS_CNL // PLATFORM_OS_CNL not defined
#undef UPCXXI_PLATFORM_OS_WSL // PLATFORM_OS_WSL not defined

// ASSUME: States simple expression cond is always true, as an annotation directive to guide compiler analysis.
// Becomes an assertion in DEBUG mode and an analysis directive (when available) in NDEBUG mode.
// This notably differs from typical assertions in that the expression must remain valid in NDEBUG mode
// (because it is not preprocessed away), and furthermore may or may not be evaluated at runtime.
// To ensure portability and performance, cond should NOT contain any function calls or side-effects.
#ifndef UPCXXI_ASSUME
#define UPCXXI_ASSUME UPCXX_ASSERT
#endif

// replacements for if statement, with branch prediction annotation
#define UPCXXI_IF_PT(expr) if (UPCXXI_PREDICT_TRUE(expr))
#define UPCXXI_IF_PF(expr) if (UPCXXI_PREDICT_FALSE(expr))


#endif // _UPCXX_CONFIG_HPP
