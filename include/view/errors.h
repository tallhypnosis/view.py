#ifndef VIEW_ERRORS_H
#define VIEW_ERRORS_H

#include <Python.h> // PyObject
#include <stdbool.h> // bool
#include <stdint.h> // uint16_t

#include <view/app.h> // ViewApp
#include <view/routing.h> // route

int route_error(
    PyObject* awaitable,
    PyObject* tp,
    PyObject* value,
    PyObject* tb
);

int fire_error(
    ViewApp* self,
    PyObject* awaitable,
    int status,
    route* r,
    bool* called,
    const char* message,
    const char* method_str
);

int server_err(
    ViewApp* self,
    PyObject* awaitable,
    uint16_t status,
    route* r,
    bool* handler_was_called,
    const char* method_str
);

int load_errors(route* r, PyObject* dict);

uint16_t hash_server_error(int status);
uint16_t hash_client_error(int status);

#endif