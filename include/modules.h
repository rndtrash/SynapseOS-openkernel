/**
 * @file modules.h
 * @author Арен Елчинян (a2.dev@yandex.com)
 * @brief Структуры и функции для модулей
 * @version 0.1.0
 * @date 24-10-2022
 * 
 * @copyright Арен Елчинян (c) 2022
 * 
 */


#include <libk.h>
#include <strings.h>
#include <versions.h>


#ifndef	_MODULES_H
#define	_MODULES_H	1


/**
 * @brief На начальном этапе у модулей будет 8 разрешений
 * 
 */
#define MODULE_PERMISSIONS_COUNT 8


/**
 * @brief Структура для хранения и передачи информации о требуемых модулю разрешениях
 * 
 */
typedef struct {
    uint32_t permissions_count;                     ///< Количество разрешений
    uint32_t permissions[MODULE_PERMISSIONS_COUNT]; ///< Список разрешений
} module_permissions_t;


/**
 * @brief Структура для хранения ответа модуля
 * 
 */
typedef struct {
    // TODO: перенести из закрытого ядра частично
} module_response_t;


/**
 * @brief Структура для хранения информации о модуле
 * 
 */
typedef struct {
    string_utf8_t *name;                        ///< Имя модуля
    version_t version;                          ///< Версия модуля
    module_permissions_t permissions;           ///< Разрешения модуля
    void (*module_post)(uint32_t*, uint32_t*);  ///< POST запрос модуля
    void *(*module_get)(uint32_t*, uint32_t*);  ///< GET запрос модуля
} module_info_t;




#endif // modules.h