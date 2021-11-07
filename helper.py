from random import randint
import math


class Helper:
    @staticmethod
    def get_list_of_nums(line):
        num = ""
        data = []
        for symbol in line:
            if symbol == '\n':
                data.append(int(num))
                break
            if symbol == ' ':
                data.append(int(num))
                num = ""
            else:
                num = num + symbol
        return data

    @staticmethod
    def get_color(color_num):
        if color_num == 1:
            return "RED"
        elif color_num == 2:
            return "ORANGE"
        elif color_num == 3:
            return "YELLOW"
        elif color_num == 4:
            return "GREEN"
        elif color_num == 5:
            return "BLUE"
        elif color_num == 6:
            return "INDIGO"
        elif color_num == 7:
            return "VIOLET"
        else:
            return "NONE"

    @staticmethod
    def get_random_list(size):
        data = []
        for i in range(0, size):
            data.append(randint(-100, 100))
        return data

    @staticmethod
    def get_len_between_nodes(first_node, second_node):
        len_x = int(first_node.X) - int(second_node.X)
        len_y = int(first_node.Y) - int(second_node.Y)
        return math.sqrt(len_x ** 2 + len_y ** 2)

    @staticmethod
    def get_input_amount_for_shape(shape_type):
        if shape_type == 1:
            return 4
        if shape_type == 2:
            return 6
        if shape_type == 3:
            return 3
        return -1
