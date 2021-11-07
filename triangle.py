from shape import Shape
from helper import Helper


class Triangle(Shape):
    def __init__(self, color, data):
        Shape.__init__(self, color)
        self.input(data)

    def input(self, line):
        Shape.set(self, line, 3)

    def output(self, file):
        out_str = (self.color + " Triangle: " +
                                " first_x = " + str(self.nodes[0].X) +
                                " first_y = " + str(self.nodes[0].Y) +
                                " second_x = " + str(self.nodes[1].X) +
                                " second_y = " + str(self.nodes[1].Y) +
                                " third_x = " + str(self.nodes[2].X) +
                                " third_y = " + str(self.nodes[2].Y) +
                                " Perimeter = " + str(self.get_perimeter()) + "\n")
        file.write(out_str)

    def get_perimeter(self):
        len_1 = Helper.get_len_between_nodes(self.nodes[0], self.nodes[1])
        len_2 = Helper.get_len_between_nodes(self.nodes[0], self.nodes[2])
        len_3 = Helper.get_len_between_nodes(self.nodes[1], self.nodes[2])
        return len_1 + len_2 + len_3
