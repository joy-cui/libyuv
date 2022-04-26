#include "Log.h"
#include <android/log.h>
void Log(const char * format, ...) {
	if (isLog) {
		va_list apptr;
		va_start(apptr, format);
		__android_log_vprint(ANDROID_LOG_DEBUG, "sdk_log", format, apptr);
		va_end(apptr);
	}
}
void LogE(const char * format, ...) {
	if (isLog) {
		va_list apptr;
		va_start(apptr, format);
		__android_log_vprint(ANDROID_LOG_ERROR, "sdk_log", format, apptr);
		va_end(apptr);
	}
}
void LogW(const char * format, ...) {
	if (isLog) {
		va_list apptr;
		va_start(apptr, format);
		__android_log_vprint(ANDROID_LOG_WARN, "sdk_log", format, apptr);
		va_end(apptr);
	}
}

void LogI(const char * format, ...) {
	if (isLog) {
		va_list apptr;
		va_start(apptr, format);
		__android_log_vprint(ANDROID_LOG_INFO, "sdk_log", format, apptr);
		va_end(apptr);
	}
}