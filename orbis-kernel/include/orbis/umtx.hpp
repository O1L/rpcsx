#pragma once

#include "error/ErrorCode.hpp"
#include "orbis-config.hpp"
#include "thread/types.hpp"
#include "time.hpp"
#include <atomic>
#include <limits>

namespace orbis {
inline constexpr ulong kUmtxUnowned = 0;
inline constexpr ulong kUmtxContested = std::numeric_limits<slong>::min();

inline constexpr auto kUsyncProcessShared = 1;

inline constexpr auto kUmutexUnowned = 0;
inline constexpr auto kUmutexContested = 0x80000000;
inline constexpr auto kUmutexErrorCheck = 2;
inline constexpr auto kUmutexPrioInherit = 4;
inline constexpr auto kUmutexPrioProtect = 8;

inline constexpr auto kUrwLockPreferReader = 2;
inline constexpr auto kUrwLockWriteOwner = 0x80000000;
inline constexpr auto kUrwLockWriteWaiters = 0x40000000;
inline constexpr auto kUrwLockReadWaiters = 0x20000000;
inline constexpr auto kUrwLockMaxReaders = 0x1fffffff;

inline constexpr auto kCvWaitCheckUnparking = 0x01;
inline constexpr auto kCvWaitAbsTime = 0x02;
inline constexpr auto kCvWaitClockId = 0x04;

inline constexpr auto kUmtxOpLock = 0;
inline constexpr auto kUmtxOpUnlock = 1;
inline constexpr auto kUmtxOpWait = 2;
inline constexpr auto kUmtxOpWake = 3;
inline constexpr auto kUmtxOpMutexTrylock = 4;
inline constexpr auto kUmtxOpMutexLock = 5;
inline constexpr auto kUmtxOpMutexUnock = 6;
inline constexpr auto kUmtxOpSetCeiling = 7;
inline constexpr auto kUmtxOpCvWait = 8;
inline constexpr auto kUmtxOpCvSignal = 9;
inline constexpr auto kUmtxOpCvBroadcast = 10;
inline constexpr auto kUmtxOpWaitUint = 11;
inline constexpr auto kUmtxOpRwRdLock = 12;
inline constexpr auto kUmtxOpRwWrLock = 13;
inline constexpr auto kUmtxOpRwUnlock = 14;
inline constexpr auto kUmtxOpWaitUintPrivate = 15;
inline constexpr auto kUmtxOpWakePrivate = 16;
inline constexpr auto kUmtxOpMutexWait = 17;
inline constexpr auto kUmtxOpMutexWake = 18;
inline constexpr auto kUmtxOpSemWait = 19;
inline constexpr auto kUmtxOpSemWake = 20;
inline constexpr auto kUmtxOpNwakePrivate = 21;
inline constexpr auto kUmtxOpMutexWake2 = 22;
inline constexpr auto kUmtxOpMutexWake3 = 23;

inline constexpr auto kSemNamed = 2;

struct umtx {
  std::atomic<ulong> owner; // Owner of the mutex
};

struct umutex {
  std::atomic<lwpid_t> owner; // Owner of the mutex
  uint32_t flags;             // Flags of the mutex
  uint32_t ceilings[2];       // Priority protect ceiling
  uint32_t spare[4];
};

struct ucond {
  std::atomic<uint32_t> has_waiters; // Has waiters in kernel
  uint32_t flags;                    // Flags of the condition variable
  uint32_t clockid;                  // Clock id
  uint32_t spare[1];                 // Spare space
};

struct urwlock {
  std::atomic<int32_t> state;
  uint32_t flags;
  uint32_t blocked_readers;
  uint32_t blocked_writers;
  uint32_t spare[4];
};

struct usem {
  std::atomic<uint32_t> has_waiters;
  std::atomic<uint32_t> count;
  uint32_t flags;
};

struct Thread;
ErrorCode umtx_lock_umtx(Thread *thread, ptr<umtx> umtx, ulong id,
                         std::uint64_t ut);
ErrorCode umtx_unlock_umtx(Thread *thread, ptr<umtx> umtx, ulong id);
ErrorCode umtx_wait(Thread *thread, ptr<void> addr, ulong id, std::uint64_t ut,
                    bool is32, bool ipc);
ErrorCode umtx_wake(Thread *thread, ptr<void> addr, sint n_wake);
ErrorCode umtx_trylock_umutex(Thread *thread, ptr<umutex> m);
ErrorCode umtx_lock_umutex(Thread *thread, ptr<umutex> m, std::uint64_t ut);
ErrorCode umtx_unlock_umutex(Thread *thread, ptr<umutex> m);
ErrorCode umtx_set_ceiling(Thread *thread, ptr<umutex> m, std::uint32_t ceiling,
                           ptr<uint32_t> oldCeiling);
ErrorCode umtx_cv_wait(Thread *thread, ptr<ucond> cv, ptr<umutex> m,
                       std::uint64_t ut, ulong wflags);
ErrorCode umtx_cv_signal(Thread *thread, ptr<ucond> cv);
ErrorCode umtx_cv_broadcast(Thread *thread, ptr<ucond> cv);
ErrorCode umtx_rw_rdlock(Thread *thread, ptr<urwlock> rwlock, slong fflag,
                         ulong ut);
ErrorCode umtx_rw_wrlock(Thread *thread, ptr<urwlock> rwlock, ulong ut);
ErrorCode umtx_rw_unlock(Thread *thread, ptr<urwlock> rwlock);
ErrorCode umtx_wake_private(Thread *thread, ptr<void> uaddr, sint n_wake);
ErrorCode umtx_wait_umutex(Thread *thread, ptr<umutex> m, std::uint64_t ut);
ErrorCode umtx_wake_umutex(Thread *thread, ptr<umutex> m, sint wakeFlags);
ErrorCode umtx_sem_wait(Thread *thread, ptr<usem> sem, std::uint64_t ut);
ErrorCode umtx_sem_wake(Thread *thread, ptr<usem> sem);
ErrorCode umtx_nwake_private(Thread *thread, ptr<void *> uaddrs,
                             std::int64_t count);
ErrorCode umtx_wake2_umutex(Thread *thread, ptr<umutex> m, sint wakeFlags);
ErrorCode umtx_wake3_umutex(Thread *thread, ptr<umutex> m, sint wakeFlags);
} // namespace orbis