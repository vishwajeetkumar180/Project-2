# Project-2
Dimention Reduction of MNIST Dataset using PCA

First i import the libraries and mnist_train dataset by using pandas then i drop the label from it and store it into another variable then i choose a label and reshape it into 28*28 dimension matrix by using .values.reshape() function after that i print 2-d image by using matplotlib function imshow().

In this project first i reduce the dimention mathematically-----

Step-1 -- First i calculate column-Standard by using scikitlearn library. 
Step-2 -- Calculate Co-variance matrix by using standardized data 
Step-3 -- Calculate Eigen Value and Eigen Vector by using scipy.linalg library and transpose the eigen vector value i does 2-d projection thats 
          why i take only the highest eigen values that covers the most of the information and its corresponding eigen vector.
Step-4 -- then i calculate the matrix multiplication of vectors and standardized_data and attached labels then plot the graph of it by using
          seaborn.FacetGrid() function.

Now we will use the PCA from scikit-learn

Step-1 -- First decompose the pca() and fit the standardized data into it and attach the labels.
Step-2 -- then we plot the pca_data by using seaborn we see that by using pca we can easily converted the large dimension dataset into the 
          small dimention by usin just 3-4 line of code.
