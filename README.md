# HPC
High Performance Computing Project
-run main.cc
-To choose Learning Algorithm, call Algorithms.setAlg(<id_alg>): 1 - GD, 2 - SGD, 3 - SVRG, 4 - MiniBatch, 5 - Hogwild, 6 - HogBatch, default method is SGD.
-Implementation of algorithms are in LearningAlgorithm.cpp: Serial algorithms: GD, SGD, SVRG, SAG. Parallel algorithms: MiniBatch, Hogwild, Hogbatch
-To config constant ( Max_iter, n_threads, eta): Constant.cpp
-Compute gradient: Gradient.cpp
-Compute accurancy: Score.cpp
