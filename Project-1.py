# Helmer Gomez  12/2022
# This program reads data from Plant Catalog and builds
# parallel arrays for the plant items,
# with each array containing the plant's full name, zone, light,
# and price, respectively.
# References:
#   https://www.w3schools.com/xml/plant_catalog.xml

def get_array(filename, field):
    array = []
    try:
        with open(filename, "r") as file:
            for line in file:
                if line.find(field) != -1:
                    unwanted = file.readline()
                    line.replace(unwanted, "")
                if line.find(field) == -1:
                    continue
                else:
                    text = line.replace(" ", "", 4)
                    text_two = text.replace("$", "")
                    text_three = text_two.replace("<" + field + ">", "", 1)
                    text_four = text_three.replace("</" + field + ">", "")
                    text_five = text_four.replace("\n", "")
                    if text_five.find(".", 1) != -1:
                        array.append(float(text_five))
                    else:
                        array.append(text_five)
    except IOError:
        print("File is missing")
        exit()
    except ValueError:
        print("Bad data")
        exit()
    except TypeError:
        print("Bad data")
        exit()
    return array


def calculate_number_of_items(common):
    item_number = len(common)
    if item_number == 0:
        print("No data")
        exit()
    return item_number


def calculate_average_price(price):
    total = 0
    try:
        for index in range(len(price)):
            total += price[index]
        average_price = total / len(price)
    except ZeroDivisionError:
        average_price = 0
    except TypeError:
        print("Bad data")
        exit()
    return average_price


def parallel_array_display(common, botanical, zone, light, price):
    for index in range(len(common)):
        print(common[index] + " (" + str(botanical[index]) + ") - " +
              str(zone[index]) + " - " + str(light[index]) + " - $" +
              str(price[index]))


def display_results(item_number, average_price):
    print(str(item_number) + " items - $" +
            str("{:.2f}".format(average_price)) +
            " average price")
        

def main():
    filename = "plant_catalog.xml"
    common = get_array(filename, "COMMON")
    botanical = get_array(filename, "BOTANICAL")
    zone = get_array(filename, "ZONE")
    light = get_array(filename, "LIGHT")
    price = get_array(filename, "PRICE")
    item_number = calculate_number_of_items(common)
    average_price = calculate_average_price(price)
    parallel_array_display(common, botanical, zone, light, price)
    display_results(item_number, average_price)


main()
