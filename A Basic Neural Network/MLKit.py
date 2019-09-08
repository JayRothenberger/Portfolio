import copy
import math

class perceptron:
    inputs = [0]
    weights = [0]
    filter = 1

    def __init__(self, filter = 1, inputs = [], weights = []):
        self.inputs = copy.copy(inputs)
        self.weights = copy.copy(weights)
        self.filter = filter

    def sign(self, x):
        if (x > 0):
            return 1
        else:
            return -1

    def sigmoid(self, x):
        e = 2.7182818284590452353602874713527
        #a decimal approximation of e, so that I don't use a function evaluation or an import
        return 1/(1+e**(-x))

    def binary(self, x):
        if(x < 0):
            return -1
        else:
            return 1

    def output(self):
        output = self.weights[0];
        for i in range(len(self.inputs)):
            output += self.inputs[i] * self.weights[i+1]
        if(self.filter == 1):
            return self.sigmoid(output)
            #just a boolean filter, not really sure about this strategy
        if(self.filter == 2):
            return self.binary(output)

        return output

    def setWeights(self, weights):
        for i in range(len(self.inputs)):
            try:
                self.inputs[i] = d[i]
            except:
                print("error in loading input, likely input array is too small")

    def setInputs(self, inputs):
        self.inputs = inputs

    def __str__(self):
        return "{weights: " + str(self.weights) + "}"


class network:
    #industry accepted rules of thumb: one hidden layer, hidden layer should have mean of output and input nodes
    #hidden nodes = samples in the set / (scaling factor * (inputs + outputs))
    #this is the maximum number which will not result in overfitting
    #in general there are superior learning results with unfiltered nodes
    layers = []
    outputs = []
    errors = []

    #all three of these need to be the same size, meaning there needs to be a well-constructed bijection between elements
    #what kind of new math major wrote that?  I understand what it means though.

    def __init__(self, inputs = 1, outputs = 1, hiddens = 0, layers = [[]]):
        for i in range(inputs):
            layers[0].append(perceptron())
        for i in range(hiddens):
            layers.append([])
            layers[i+1].append([perceptron()]*int((inputs+outputs)/2))
        for i in range(outputs):
            layers.append([])
            layers[len(layers)-1].append(perceptron())

        self.layers = layers
        for i in range(len(layers)):
            self.errors.append([])
            self.outputs.append([])
            for j in range(len(layers[i])):
                self.errors[i].append(0)
                self.outputs[i].append(0)
                if(i):
                    for k in range(len(layers[i-1])+1):
                        self.layers[i][j].weights.append(1)
                else:
                    for k in range(inputs+1):
                        self.layers[i][j].weights.append(1)

    def sigmoid(self, x):
        e = 2.7182818284590452353602874713527
        #a decimal approximation of e, so that I don't use a function evaluation or an import
        return 1/(1+e**(-x))


    def train(self, inputFile, rate = .1):
        #assume that the input file is line separated tuples of data and classification pairs
        for i in inputFile:
            self.update(i[0], i[1], rate)

    def update(self, datum, target, rate = 1):
        self.evaluate(datum)
        self.error(target)
        for i in range(len(self.layers)):
            for j in range(len(self.layers[i])):
                for k in range(len(self.layers[i][j].weights)):
                    inputs = self.layers[i][j].inputs
                    if(k == 0):
                        self.layers[i][j].weights[k] += rate * self.errors[i][j]
                    else:
                        self.layers[i][j].weights[k] += rate * self.errors[i][j] * inputs[k-1]
    #this should update the weights to make them more correct

    def error(self, target):
        for i in range(len(target)):
            target[i] = self.sigmoid(target[i])

        for i in range(len(self.layers[len(self.layers)-1])):
            self.errors[len(self.errors)-1][i] = self.layers[len(self.layers)-1][i].output()*(1-self.layers[len(self.layers)-1][i].output())*(target[i] - self.layers[len(self.layers)-1][i].output())
        #for the last layer
        for i in range(len(self.layers)-1):
            # for all of the other layers after that
            for j in range(len(self.layers[len(self.layers)-i-2])):
                #for elements in that layer
                h = len(self.layers)-i-2
                #the current layer
                k = 0
                for l in range(len(self.layers[h+1])):
                    k += self.layers[h+1][l].weights[j+1]*self.errors[h+1][l]
                self.errors[h][j] = self.outputs[h][j]*(1-self.outputs[i][j])*k
    #this function should propagage the errors matrix.  Assumes that the output matrix has been evaluated


    def evaluate(self, inputs):
        n = inputs
        for j in range(len(self.layers)):
            if(j != 0):
                n = self.outputs[j-1]
            for i in range(len(self.layers[j])):
                self.layers[j][i].setInputs(n)
                self.outputs[j][i] = self.layers[j][i].output()
    #this function should propagate the outputs matrix



