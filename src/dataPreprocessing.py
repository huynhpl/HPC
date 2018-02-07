import pandas as pd

from sklearn.preprocessing import LabelEncoder
from sklearn.model_selection import train_test_split

def Preprocessing(filename, label):
    dataset = pd.read_csv(filename)
    y = pd.DataFrame(dataset.iloc[:,label])
    X = dataset.drop(dataset.columns[label], axis=1)

    # normalize sets
    lenc = LabelEncoder()
    X = pd.DataFrame(X.apply(lenc.fit_transform))

    if label == 0:
    #dataset agaricus
        y = pd.DataFrame(y.applymap(lambda  r: 1 if r=="p" else 0))
    elif label == 1:
    #dataset wdbc
        y = pd.DataFrame(y.applymap(lambda  r: 1 if r=="M" else 0))
        # print (y.head(5))
    elif label == 34:
    #dataset ionosphere
        y = pd.DataFrame(y.applymap(lambda  r: 1 if r=="g" else 0))

    X_train, X_test, y_train, y_test = train_test_split(X,y,test_size=0.4)

    return X_train, X_test, y_train, y_test

filename = '../data/agaricus-lepiota.data.txt'
X_train, X_test, y_train, y_test = Preprocessing(filename, 0)

def WriteData(X_train, y_train, X_test):
    X_train.to_csv('../data/X_train.txt', header=False, index=False, sep=',', mode='a')
    y_train.to_csv('../data/y_train.txt', header=False, index=False, sep=' ', mode='a')
    X_test.to_csv('../data/X_test.txt', header=False, index=False, sep=',', mode='a')
    y_test.to_csv('../data/y_test.txt', header=False, index=False, sep=' ', mode='a')

WriteData(X_train, y_train, X_test)
print("OK")