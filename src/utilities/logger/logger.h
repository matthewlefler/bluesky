#ifndef LOGGER_H
#define LOGGER_H

// up to 256 possible values

typedef enum LOG_LEVEL : unsigned char {
    LOG_LEVEL_VERBOSE,
    LOG_LEVEL_DEBUG,
    LOG_LEVEL_INFO,
    LOG_LEVEL_WARNING,
    LOG_LEVEL_ERROR,
    LOG_LEVEL_FATAL,
} LOG_LEVEL;

#define LOG_LEVEL_VERBOSE_STRING "VERBOSE "
#define LOG_LEVEL_DEBUG_STRING   "DEBUG   "
#define LOG_LEVEL_INFO_STRING    "INFO    "
#define LOG_LEVEL_WARNING_STRING "WARNING "
#define LOG_LEVEL_ERROR_STRING   "ERROR   "
#define LOG_LEVEL_FATAL_STRING   "FATAL   "
#define LOG_LEVEL_UNKNOWN_STRING "UNKNOWN "

void set_log_level(LOG_LEVEL level);

void log_message(LOG_LEVEL level, const char* message, ...);

const char* log_level_to_string(LOG_LEVEL level);

#endif
