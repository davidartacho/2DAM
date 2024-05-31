from turtle import mode
import pandas as pd
from sklearn.model_selection import train_test_split
import cv2
import numpy as np
import os
from pose_estimation import PoseEstimation
import pandas
from args import get_args, show_args
import pickle
from sklearn.ensemble import GradientBoostingClassifier
from sklearn.neural_network import MLPClassifier
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import classification_report, confusion_matrix
from sklearn.metrics import ConfusionMatrixDisplay
from sklearn.svm import SVC
from sklearn.neighbors import KNeighborsClassifier
videos_path = "../VideosDeEntrenamiento"
expected_pixels = 257
frame_rate = 5
body_parts = ["nose", "leftEye", "rightEye", "leftEar", "rightEar", "leftShoulder", "rightShoulder",
                  "leftElbow", "rightElbow", "leftWrist", "rightWrist", "leftHip", "rightHip", "leftKnee",
                  "rightKnee", "leftAnkle", "rightAnkle"]
"""
data = None
pe = PoseEstimation("../posenet_mobilenet_v1_100_257x257_multi_kpt_stripped.tflite")
data = None

for root, dirs, files in os.walk(videos_path):
    for class_name in dirs:
        class_path = os.path.join(root, class_name)
        videos = [x for x in os.listdir(class_path) if x.endswith(".mp4")]
        print("Videos", videos)
        for file in videos:
            video_data = None
            video_path = os.path.join(class_path, file)
            video = cv2.VideoCapture(video_path)
            print("video capturado ", video)
            video_rate = int(np.round(video.get(cv2.CAP_PROP_FPS) / frame_rate))
            print("FPS ", video_rate)
            if class_name == "Caidas":
                label = "Fall"
            elif class_name == "Recover":
                label = "Recover"
            elif class_name == "Normal":
                label = "Nothing"
            while video.isOpened():
                frame_number = video.get(1)  # current frame number
                ret, frame = video.read()
                print("ret", ret)
                if not ret:
                    break
                if frame_number % video_rate == 0:
                    frame = pe.make_square(frame, pe.expected_pixels)
                    pose = pe.get_pose_estimation(frame)
                    # Normalizing scale
                    max_val = np.max(np.abs(pose))
                    pose = pose / max_val  
                    pose = pose.reshape(-1)
                    if video_data is None:
                        video_data = pose
                        print("video_data is NONE")
                    else:
                        video_data = np.hstack((video_data, pose))
                        print("video_data no es NONE")
            video.release()
            video_data = np.append(video_data, label)
            if data is None:
                data = video_data
                print("DATAZOS ")
            else:
                print("data shape", data.shape)
                print("video_data", video_data.shape)
                data = np.vstack((data, video_data))



header = None

body_parts_len = len(body_parts)
data_len = len(data[0]) - 1
elements_per_part = 2  
frame = -1
for i in range(0, data_len, elements_per_part):
    if i % body_parts_len == 0:
        frame += 1
    body_part = body_parts[int(i / elements_per_part) % body_parts_len]
    title = "Frame_{}_{}".format(frame, body_part)
    if header is None:
        header = "{}_X".format(title)
    else:
        header = np.hstack((header, "{}_X".format(title)))
    header = np.hstack((header, "{}_Y".format(title)))
    # header = np.hstack((header, "{}_Reliable".format(title)))
header = np.hstack((header, "class"))

pd.DataFrame(data).to_csv("data/data4.csv", header=header, index=False)

# Crear un DataFrame a partir de los datos
#df = pd.DataFrame(data, columns=header)

#df.to_csv("data/data2.csv", index=False)
"""

#Entrenamiento

data = pd.read_csv("data/data3.csv")
y = data[:]['class']
data = data.iloc[: , :-1]
x_train, x_test, y_train, y_test = train_test_split(data, y, random_state=42, test_size=0.2)

#Metodo para mostrar resultados
def mostrar_resultados(modelo, algoritmo):

    # Predicciones del modelo
    y_pred = modelo.predict(x_test)

    # Matriz de confusión
    cm = confusion_matrix(y_test, y_pred)
    print("{} report \n".format(algoritmo), classification_report(y_test, y_pred))
    print("Matriz de Confusión:")
    print(cm)

    # Falsos positivos y falsos negativos de caídas
    fp = np.sum((y_pred == "Fall") & (y_test != "Fall"))
    fn = np.sum((y_pred != "Fall") & (y_test == "Fall"))
    print("FP = {} | FN = {}".format(fp, fn))


# Modelo RandomForestClassifier
random_forest_model = RandomForestClassifier(criterion="gini", min_samples_split=2, max_depth=None, n_estimators=50, random_state=16)
random_forest_model.fit(x_train, y_train)
mostrar_resultados(random_forest_model, "Random Forest Classifier")

# Modelo MLPClassifier
neural_network_model = MLPClassifier(solver="lbfgs", activation="identity", hidden_layer_sizes=20)
neural_network_model.fit(x_train, y_train)
mostrar_resultados(neural_network_model, "Neural Network Classifier")

# Modelo GradientBoostingClassifier
gradient_boosting_model = GradientBoostingClassifier(learning_rate=0.1, n_estimators=50, random_state=20)
gradient_boosting_model.fit(x_train, y_train)
mostrar_resultados(gradient_boosting_model, "Gradient Boosting Classifier")

#Buscamos qué algoritmo da menos falsos negativos

random_forest_fp = 0
random_forest_fn = 0
gradient_boosting_fp = 0
gradient_boosting_fn = 0
#Este metodo se encarga de recoger los falsos positivos y los falsos negativos
def get_fp_fn(predecido, real, estado, fp, fn):
    for i in range(len(predecido)):
        if predecido[i] == estado != real[i]:
            fp += 1
        elif real[i] == estado != predecido[i]:
            fn += 1
    return fp, fn

veces_a_repetir = 100
for i in range(veces_a_repetir):
    print("Empezando")
    rf_model = RandomForestClassifier(n_estimators=50, criterion="gini", min_samples_split=2, max_depth=None)
    gb_model = GradientBoostingClassifier(learning_rate=0.1, n_estimators=50)
    rf_model.fit(x_train, y_train)
    gb_model.fit(x_train, y_train)
    rf_y = rf_model.predict(x_test)
    gb_y = gb_model.predict(x_test)
    print("Continuando")
    np_y_test = y_test.to_numpy()
    random_forest_fp, random_forest_fn = get_fp_fn(rf_y, np_y_test, "Fall", random_forest_fp, random_forest_fn)
    gradient_boosting_fp, gradient_boosting_fn = get_fp_fn(gb_y, np_y_test, "Fall",gradient_boosting_fp, gradient_boosting_fn)

muestras_totales = len(np_y_test) * veces_a_repetir
print("Random Forest     | FP = {}, {}% | FN = {}, {}%".format(random_forest_fp, random_forest_fp/muestras_totales*100,
                                                             random_forest_fn, random_forest_fn/muestras_totales*100))
print("Gradient Boosting | FP = {}, {}% | FN = {}, {}%".format(gradient_boosting_fp, gradient_boosting_fp/muestras_totales*100,
                                                            gradient_boosting_fn, gradient_boosting_fn/muestras_totales*100))

#Guardamos el mejor modelo
"""
best_random_forest_model = RandomForestClassifier(criterion="gini", min_samples_split=2, max_depth=None, n_estimators=50, random_state=16)
best_random_forest_model.fit(data, y)
"""

if gradient_boosting_fp + gradient_boosting_fn < random_forest_fp + random_forest_fn:
    best_model = gradient_boosting_model
    print("El mejor modelo es Gradient Boosting")
else:
    best_model = random_forest_model
    print("El mejor modelo es Random Forest")


pickle.dump(best_model, open("model/HSC5.sav", 'wb'))
#import pickle
#base_model = pickle.load(open("model/HSC.sav", 'rb'))
