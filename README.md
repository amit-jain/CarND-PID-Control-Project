# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets) == 0.13, but the master branch will probably work just fine
  * Follow the instructions in the [uWebSockets README](https://github.com/uWebSockets/uWebSockets/blob/master/README.md) to get setup for your platform. You can download the zip of the appropriate version from the [releases page](https://github.com/uWebSockets/uWebSockets/releases). Here's a link to the [v0.13 zip](https://github.com/uWebSockets/uWebSockets/archive/v0.13.0.zip).
  * If you run OSX and have homebrew installed you can just run the ./install-mac.sh script to install this
* Simulator. You can download these from the [project intro page](https://github.com/udacity/CarND-PID-Control-Project/releases) in the classroom.

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

## Editor Settings

We've purposefully kept editor configuration files out of this repo in order to
keep it as simple and environment agnostic as possible. However, we recommend
using the following settings:

* indent using spaces
* set tab width to 2 spaces (keeps the matrices in source code aligned)

## Code Style

Please (do your best to) stick to [Google's C++ style guide](https://google.github.io/styleguide/cppguide.html).

## Project Instructions and Rubric

Note: regardless of the changes you make, your project must be buildable using
cmake and make!

More information is only accessible by people who are already enrolled in Term 2
of CarND. If you are enrolled, see [the project page](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/f1820894-8322-4bb3-81aa-b26b3c6dcbaf/lessons/e8235395-22dd-4b87-88e0-d108c5e5bbf4/concepts/6a4d8d42-6a04-4aa6-b284-1697c0fd6562)
for instructions and the project rubric.

## Reflection

The PID controller is comprised of 3 parts. The first term (Kp) is proportional to the cross track error (cte) between 
the required target value and the actual value. The second term (Kd) is proportional to the derivative of the error 
and the last term (Ki) is proportional to the integral of the error.

The selection of these 3 coefficients to derive the total correction is what matters:
* Proportional Coefficient
    If Kp is too large, this can cause the system to start to oscillate due to too much input being applied.
    When Kp is small, the vehicle will slowly turn in the correct direction to reduce the error.

* Differential Coefficient
    Kd controls the rate of change of the error. Because of this, it can be used to either dampen or exaggerate
     the effects of the proportional term. An appropriate value can be used to smooth the output.
 
* Integral coefficient
    Ki is used to counter the steady-state error or the drift in built in the vehicle. If there is no apparent drift 
    then this component would keep increasing and would cause larger changes to the correction.

The final parameters were chosen manually through different experiments as it was not easy to use twiddle etc. since 
the car would die most of the time in the simulator and feedback would be difficult to obtain.
`
P coeff = 0.1
I coeff  = 0
D coeff = 0.8`

The P coefficient was chosen to minimize the oscillations from one edge to the other.
The D coefficient was chosen so as the system recovers smoothly.
The I coefficient was chosen to be 0 as the car running in the simulator did not seem to have any drift.

![PID Controller](PID_Controller.mp4)