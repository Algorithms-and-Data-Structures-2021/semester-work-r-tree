import argparse
import random

DATAS = [100, 500, 1000, 5000, 10000, 25000, 50000, 100000, 250000, 500000, 750000, 1000000, 2500000, 5000000]

def parse_args():
    parser = argparse.ArgumentParser(description="Random numbers generator")

    parser.add_argument('output',
                        type=str,
                        help='output CSV file, e.g. data/output.csv')

    parser.add_argument('--samples',
                        type=int,
                        default=100,
                        help='number of samples to generate (default: {})'.format(100))

    return parser.parse_args()


if __name__ == '__main__':
    args = parse_args()

    # валидация аргументов
    if args.samples < 0:
        raise ValueError('Number of samples must be greater than 0.')

    # запись данных в файл
    for j in range(len(DATAS)):
        with open(args.output + "/" + str(DATAS[j]) + ".csv", 'w') as file:
            for i in range(DATAS[j]):
                x_coord = random.randint(0, 100)
                y_coord = random.randint(0, 100)

                file.write(str(x_coord) + "," + str(y_coord) + "\n")