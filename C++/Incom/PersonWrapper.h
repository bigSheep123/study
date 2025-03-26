// PersonWrapper.h
#ifndef PERSONWRAPPER_H
#define PERSONWRAPPER_H

#ifdef __cplusplus
extern "C" {
#endif


typedef struct hello* PersonHandle;

PersonHandle Person_create(int age);
void Person_destroy(PersonHandle handle);
int Person_getAge(PersonHandle handle);
void Person_setAge(PersonHandle handle, int age);

#ifdef __cplusplus
}
#endif

#endif
