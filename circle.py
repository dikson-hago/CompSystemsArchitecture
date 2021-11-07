from shape import Shape
import math


class Circle(Shape):
    def __init__(self, color, line):
        Shape.__init__(self, color)
        self.radius = 0
        self.is_valid = True
        self.input(line)

    def input(self, data):
        Shape.set(self, data, 1)
        self.radius = data[2]
        if self.radius < 0:
            self.is_valid = False

    def output(self, file):
        out_str = (self.color + " Circle: " +
                                " center_x = " + str(self.nodes[0].X) +
                                " center_y = " + str(self.nodes[0].Y) +
                                " radius = " + str(self.radius) +
                                " Perimeter = " + str(self.get_perimeter()) + "\n")
        file.write(out_str)
        if not self.is_valid:
            out_str = "This Circle is invalid\n"
            file.write(out_str)

    def get_perimeter(self):
        return 2 * math.pi * self.radius

