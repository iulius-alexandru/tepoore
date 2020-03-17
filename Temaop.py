import pandas as pd
import numpy as np
from sklearn import preprocessing
from sklearn import svm
import matplotlib.pyplot as plt
from sklearn.impute import SimpleImputer as imputer
from sklearn.neighbors import KNeighborsClassifier
from sklearn.model_selection import StratifiedShuffleSplit
neigh = KNeighborsClassifier(n_neighbors=5)
data=pd.read_csv("Bucharest_HousePriceDataset.csv")
imp=imputer(strategy="median")
imp.fit(data)
data_num=imp.transform(data)
split = StratifiedShuffleSplit(n_splits=5, test_size=0.2, random_state=42)
for train_index, test_index in split.split(data,data["Scor"]):
    strat_train_set = data.loc[train_index]
    strat_test_set = data.loc[test_index]

train_data=strat_train_set.drop(["Total Etaje","Etaj","Scor"],axis=1)
test_data=strat_test_set.drop(["Total Etaje","Etaj","Scor"],axis=1)
train_labels=np.array(strat_train_set["Scor"])
test_labels=np.array(strat_test_set["Scor"])
scalar=preprocessing.StandardScaler()
scalar.fit(train_data)
train_data=scalar.transform(train_data)
test_data=scalar.transform(test_data)
neigh.fit(train_data,train_labels)
my_est=neigh.predict(test_data)
accuracy=np.sum([(my_est[i]==test_labels[i]) for i in range(len(test_labels))])/len(test_labels)
print(accuracy)

