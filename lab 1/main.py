import math

class Figure:
    def __init__(self, radius):
        self.__radius = radius  # Приватне поле
        print("Class created")

    def __del__(self): # Деконструктор
        print("Class deleted")

    @property
    def Area(self):
        return math.pi * self.__radius ** 2 # Публічна властивість

    def GetFigure(self):
        return "Circle" 

figure = Figure(5)  # Створення екзепляра класу
print(f"Shape type: {figure.GetFigure()}")
print(f"Area shape: {figure.Area:.2f}")
