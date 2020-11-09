# Unit Testing Example

## Introduction:

This project is generated to understand the Unit Testing with Unity Test FrameWork and Code Coverage tool gcov.
We have source file [fifo.c](https://github.com/Akshay1595/Unit_Testing_Example/blob/master/fifo.c) which we want to test and ensure it has not missed any scenario and development is appropriate. A unit test exectution and coerage report help us to improve development process.

## Description:

### Fifo (First in First out):
As name suggest, this project is about implementation of fifo. Fifo has integer as an data type.
Requirement of FIFO is as follows:
1. Fifo can be initialized by any number of nodes.
2. Data added first need to deleted first.
3. If user attempts to write when FIFO is full, it should fail.
4. If user attempts to delete when FIFO is empty, it should fail.

### How we develop the code?
- Using TDD approach.
1. We write the code with failing status in return.
2. We look at the requirement and finalize the test cases covering all possible combinations and scenarios.
3. We then write the test code first. Execute the test which should fail.
4. Then we write the code to pass the tests.
5. We repeat step 3 and 4 till we complete unit testing of all requirements.

### How to quantify your test code?
- Quantifying our test code is much necessary. We need to ensure we are covering all the possible scenario. 
- To do that coverage will help us. Coverage will let us know how much part of firmware code it has covered.
- It may let us know dead code or condition that test code might have missed to cover.
- Functional coverage and line coverage help us to understand if we have covered everything
- Gcov shows lines we have covered in blue. [line coverage](https://github.com/Akshay1595/Unit_Testing_Example/blob/master/Unit_Testing_Example/fifo.c.gcov.html)
- A sample of code coverage snapshot:
![code coverage snapshot](https://github.com/Akshay1595/Unit_Testing_Example/blob/master/coverage_snapshot.PNG)

### How Unit testing is useful?
- If we are using unit testing with TDD, best practise is, don't commit code until Unit tests have covered
- all the lines you have written. Also unit test report should be all testcases passed. 
- Commit message need to have location to test log and coverage report.
- In the later stage of development, if someone else makes change in my code, unit tests will ensure that
- he has not missed anything if he gets unit test exectution results and code coverage report.

### files:
- Source file: [fifo.c](https://github.com/Akshay1595/Unit_Testing_Example/blob/master/fifo.c)
- Code Coverage report: [report](https://github.com/Akshay1595/Unit_Testing_Example/blob/master/Unit_Testing_Example/index.html)
- Module Add_node testcases: [test_add_node.c](https://github.com/Akshay1595/Unit_Testing_Example/blob/master/test_add_node.c)
- Module Del_node testcases: [test_del_ndoe.c](https://github.com/Akshay1595/Unit_Testing_Example/blob/master/test_del_node.c)
- Modeule InitFifo testcases: [test_init_fifo.c](https://github.com/Akshay1595/Unit_Testing_Example/blob/master/test_init_fifo.c)
- Test Execution Report: [test_report.txt](https://github.com/Akshay1595/Unit_Testing_Example/blob/master/test_report.txt)

### How to do it?
1. Download [Unit_Testing_Example](https://github.com/Akshay1595/Unit_Testing_Example) repository.
2. Compile with command: $ gcc -o output  fifo.c test.c test_init_fifo.c test_add_node.c test_del_node.c unity.c --coverage.
3. Execute the ouput: $./output
4. Install lcov and generate coverage info: $lcov --capture --directory . --output-file=coverage.info
5. Generate the html file: $ genhtml coverage.info
6. Look for index.html file and browse.
