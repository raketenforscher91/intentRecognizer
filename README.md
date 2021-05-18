# intentRecognizer

Build system : Cmake (tested on mac with v3.18.2 and ubuntu with v3.16.3) minimum supported version 3.7

Dependencies:
  C++17
  googletest (for ubuntu sudo apt-get install libgtest-dev, for mac brew install googletest)


Build instructions:
  "mkdir build && cd build && cmake .. && make
  
  
Example commands:
  ./IntentRec How is the Weather today!
  ./IntentRecTest -> runs test cases with googletest.
