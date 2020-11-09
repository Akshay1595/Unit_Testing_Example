#Unit Testing Example

## Introduction:

This project is generated to understand the Unit Testing with Unity Test FrameWork and Code Coverage tool gcov.
We have source file fifo.c which we want to test and ensure it has not missed any scenario and development is firm.
To test this we have added tests for each module of the fifo for ex.
1] test_add_node.c 
2] test_del_node.c 
3] test_init_fifo.c
After unit test exectution we get test coverage report.

see documentation [here](myLib/README.md)

## Description:

### Fifo (First in First out):
As name suggest, this project is about implementation of fifo. Fifo has integer as an data type.
Requirement of FIFO is as follows:
1. Fifo can be initialized by any number.
2. Data added first need to deleted first.
3. If user attempts to write when FIFO is full, it should fail.
4. If user attempts to delete when FIFO is empty, it should fail.
5. Other cases FIFO should work as expected.

### How we develop the code?
- Using TDD approach.
1. We write the code with failing status in return.
2. We look at the requirement and finalize the test cases covering all possible combinations and scenarios.
3. We then write the test code first. Execute the test which should fail.
4. Then we write the code to pass the tests.
5. We repeat step 3 and 4 till we finish the all requirements.

### How to quantify your test code?
- Quantifying our test code is much necessary. We need to ensure we are covering all the possible scenario. 
- To do that coverage will help us. Coverage will let us know how much part of firmware code it has covered.
- It may let us know dead code or condition that test code might have missed to cover.


### How Unit testing is useful?
- If we are using unit testing with TDD, best practise is, don't commit code until Unit tests have covered
- all the lines you have written. Also unit test report should be all testcases passed. 
- Commit message need to have location to test log and coverage report.
- In the later stage of development, if someone else makes change in my code, unit tests will ensure that
- he has not missed anything if he gets unit test exectution results and code coverage report.

Fifo.c :
Fifo.c Code Coverage report :
Add_node testcases :
Del_node testcases : 
InitFifo testcases :
