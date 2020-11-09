#include <stdlib.h>
#include <stdio.h>
#include "unity.h"
#include "fifo.h"
#include "test.h"

int main() {
    UNITY_BEGIN();
    tests_for_initFifo();
    tests_for_addNode();
    tests_for_delNode();
    return UNITY_END(); 
}