***The project’s primary goal is to predict the activity state of the participants using the provided thousands of sixty-second sequences of biological sensor data. We hope to achieve high accuracy for this classification problem. ​

The data set that was provided contains 3 files:​

-train.csv - the training set, comprising ~26,000 60-second recordings of thirteen biological sensors for almost one thousand experimental participants. The file contains a total of 16 columns:​

-sequence - a unique id for each sequence​

-subject - a unique id for the subject in the experiment​

-step - time step of the recording, in one-second intervals​

-sensor_00 - sensor_12 - the value for each of the thirteen sensors at that time step​

​

-train_labels.csv - the class label for each sequence. Sequence - the unique id for each sequence. state - the state associated with each sequence. This is the target that you are trying to predict.​

-test.csv - the test set. For each of the ~12,000 sequences, you should predict a value for that sequence's state.​
