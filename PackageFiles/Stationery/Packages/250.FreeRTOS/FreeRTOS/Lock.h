/** ********************************************************************
 * @file   Lock.h
 * @copyright (c) 2017-2018 Richard Damon
 * @author Richard Damon <richard.damon@gmail.com>
 * @parblock
 * MIT License:
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * It is requested (but not required by license) that any bugs found or
 * improvements made be shared, preferably to the author.
 * *
 * @date Jun 6, 2017 Created
 *
 *  Description:
 * @brief Lock Wrapper
 *
 *  Wrapper classes for Basic Lock Functionality for FreeRTOS.
 *
 * @ingroup FreeRTOSCpp
 **********************************************************************/
#ifndef FREERTOS_FREERTOSPP_LOCK_H_
#define FREERTOS_FREERTOSPP_LOCK_H_

#include "FreeRTOS.h"

namespace FREERTOS_CPP {

/**
 * A Base class to provide block based locking capability.
 * @ingroup FreeRTOSCpp
 */

class Lockable {
public:
	Lockable() {}
	virtual ~Lockable() {}

	virtual bool take(TickType_t wait = portMAX_DELAY) = 0;
	virtual bool give() = 0;
private:
#if __cplusplus < 201101L
    Lockable(Lockable const&);      ///< We are not copyable.
    void operator =(Lockable const&);  ///< We are not assignable.
#else
    Lockable(Lockable const&) = delete;      ///< We are not copyable.
    void operator =(Lockable const&) = delete;  ///< We are not assignable.
#endif // __cplusplus
};

/**
 * Class to hold a block based lock. (auto unlocks on in its destructor)
 * @ingroup FreeRTOSCpp
 */
class Lock {
public:
	Lock(Lockable& mylockable, bool locked = true, TickType_t wait = portMAX_DELAY);
	virtual ~Lock();

	bool lock(TickType_t wait = portMAX_DELAY);
	void unlock();
	bool locked() const { return lockCnt > 0; }
private:
	Lockable& lockable;
	int		lockCnt;

#if __cplusplus < 201101L
    Lock(Lock const&);      ///< We are not copyable.
    void operator =(Lock const&);  ///< We are not assignable.
#else
    Lock(Lock const&) = delete;      ///< We are not copyable.
    void operator =(Lock const&) = delete;  ///< We are not assignable.
#endif // __cplusplus
};

}; // end namespace FREERTOS_CPP

#endif /* FREERTOS_FREERTOSPP_LOCK_H_ */
