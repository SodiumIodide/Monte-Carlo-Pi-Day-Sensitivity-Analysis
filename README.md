# Monte Carlo Pi Day Sensitivity Analysis

In honor of Pi Day (March 14) 2017, I decided to try my hand at a short little [challenge](http://www.fluentcpp.com/2017/03/02/the-pi-day-challenge-for-expressive-code-in-c/).

There is no attempt made at threading or increasing the speed of the calculations, as I was using the Linux Subsystem on Windows GCC compiler and wanted to limit it to internal libraries as much as possible. That is, no Boost additions. I am aware that built-in threading libraries do exist, but they are a bit of a pain to get functioning over a "cross-platform" compilation like that.

This is a problem that I've done before for homework assignments and the like, but this challenge asked specifically for a sensitivity analysis.

This short code has an output of a matrix of variations for a number of particles (10^m for m between 0 and 7 inclusive) and a circle's radius (10^n for n between 0 and 9 inclusive).

In the output, columns control increasing particle counts, and subsequent rows control increasing radius size.

In my experience with Monte Carlo codes, my estimation was that the particle generation number would massively control the output, and that appears to be the data shown. An increasing radius does improve precision as a general trend, but only very roughly.

Random generation does play a part in the result. Seeding on system time would be faster and produce a generally more "perturbed" result, but I wanted to try the implementation of the "true" random generator in the built-in libraries. Without any seeding, the order of generation differs only by result magnitudes, and so the increase in radius is completely meaningless.

I thought about integrating a version of the MCNP random number generator that I have available, but I fear that it would not be wise to publish that on GitHub.

Do note that the `<random>` header does require a C++ 11 definition for your compiler.
