from rectangle import Rectangle
from triangle import Triangle
from circle import Circle
from helper import Helper


class Container:
    def __init__(self):
        self.figures = []

    def set_shape(self, data, shape_type, shape_color):
        if len(data) != Helper.get_input_amount_for_shape(shape_type):
            return False
        if shape_type == 1:
            self.figures.append(Rectangle(shape_color, data))
        elif shape_type == 2:
            self.figures.append(Triangle(shape_color, data))
        elif shape_type == 3:
            self.figures.append(Circle(shape_color, data))
        else:
            return False
        return True

    def output(self, file):
        self.sort_container()
        size = len(self.figures)
        file.write("Container contains " + str(size) + " elements \n")
        index = 0
        for figure in self.figures:
            file.write(str(index) + ": ")
            figure.output(file)
            index += 1

    def sort_container(self):
        size = len(self.figures)
        for i in range(0, size):
            for j in range(size - 1, i, -1):
                if self.figures[j].get_perimeter() < self.figures[j - 1].get_perimeter():
                    self.figures[j], self.figures[j - 1] = self.figures[j - 1], self.figures[j]
