#!/usr/bin/python3
""" script que lee stdin línea por línea y calcula métricas """
import sys

if __name__ == '__main__':

    def imprime_resultados(statusCodes, fileSize):
        """ Estadisticas """
        print("File size: {:d}".format(fileSize))
        for statusCode, times in sorted(statusCodes.items()):
            if times:
                print("{:s}: {:d}".format(statusCode, times))

    statusCodes = {"200": 0,
                   "301": 0,
                   "400": 0,
                   "401": 0,
                   "403": 0,
                   "404": 0,
                   "405": 0,
                   "500": 0
                   }
    fileSize = 0
    n_lines = 0

    try:
        """ leemos la entrada stdin """
        for line in sys.stdin:
            if n_lines != 0 and n_lines % 10 == 0:
                """ After every 10 lines, print from the beginning """
                imprime_resultados(statusCodes, fileSize)
            n_lines += 1
            data = line.split()
            try:
                """ calcula """
                statusCode = data[-2]
                if statusCode in statusCodes:
                    statusCodes[statusCode] += 1
                fileSize += int(data[-1])
            except:
                pass
        imprime_resultados(statusCodes, fileSize)
    except KeyboardInterrupt:
        """ interrupcion del usuario"""
        imprime_resultados(statusCodes, fileSize)
        raise
