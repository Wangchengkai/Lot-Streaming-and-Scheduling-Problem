The main code is shown below.
Among them, small-scale has 5 different products, large-scale has 10 different products.
The data corresponding to the small scale case is:
***lotstreaming-paper_LSSP_small-scale.cpp***
We give detailed comments on the code.

In the large-scale code, we give the three copies of the code required for machine learning acceleration (ML-DPH), i.e., the copy generating the training data, the copy using the predicted result to  accelerate, and the copy to compute the lower bound. 
***lotstreaming-paper_LSSP_big-scale_get-the-training-data-of-ML.cpp***
***lotstreaming-paper_LSSP_big-scale_use-ML-to-accelerate.cpp***
***lotstreaming-paper_LSSP_big-scale_get-the-lower-bound.cpp***
Note that, if you set the parameter “useMachineLearningResultToControlArcs” in these code to 0, it will not use machine learning for acceleration. (Thus it becomes the code of DP-heuristic)

The code to training the KNN model is showing in:
***the-KNN-training-function.ipynb (python)***

