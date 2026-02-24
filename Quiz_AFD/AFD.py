import sys

def afd(cadena):
    estado = 0
    for caracter in cadena:
        if estado == 0:
            if caracter == '+': estado = 1
            elif 'A' <= caracter <= 'Z': estado = 3
            else: return "NO ACEPTA"
        elif estado == 1:
            if caracter == '+': estado = 2
            else: return "NO ACEPTA"
        elif estado == 2:
            return "NO ACEPTA"
        elif estado == 3:
            if ('a' <= caracter <= 'z') or ('0' <= caracter <= '9'): estado = 3
            else: return "NO ACEPTA"
    
    if estado == 1: return "SUMA"
    if estado == 2: return "INCR"
    if estado == 3: return "ID"
    return "NO ACEPTA"

if __name__ == "__main__":
    if len(sys.argv) > 1:
        try:
            with open(sys.argv[1], 'r') as f:
                for palabra in f.read().split():
                    print(afd(palabra))
        except FileNotFoundError:
            pass