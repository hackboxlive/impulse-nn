# impulse-nn

A artificial neural network library written in C++14, written from scratch. Currently, it trains on a feed-forward network, which to my surprise, works fine. The activating function here used is the fast sigmoid function, and the derivative function is also of the same.

The impulse-nn implements backpropagation to train the neural nets. The backpropagation tries to reduce the error incurred in every iteration of the epoch.

Currently, 1 million epoches are executed which take a time of around 20 to 30 seconds to train the neural network. While in other languages, the same factors take a few minutes to train.

## How to run?

Use the command `./impulse` to run the project. You can build the project by using `make` command while in the project directory.

(I don't know much about it :p)

## What did it teach me?

1. I knew about backpropagation and feed-forward neural nets. But never thought implementing them would be such a pain. A lot of hours in debugging taught me to write cleaner code.

2. I learned a great deal about how to write makefiles, which turns out to be pretty cool.

3. How to handle header files and link them to other files for communication.
