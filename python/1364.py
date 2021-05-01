def main():
    emoticons = list()
    testCases = list()
    emote = ""
    contEmotes = ""
    continuar = True
    while (continuar):
        pos = partirNumeros(input())
        n = pos[0]
        m = pos[1]
        contEmotes = 0
        emoticons.clear()
        testCases.clear()
        if not (n==0 and m==0):
            for i in range(n):
                emote = input()
                emoticons = insertarOrdenado(emoticons, emote, 0, len(emoticons)-1)
            for i in range(m):
                text = input()
                testCases.append(text)
            for i in range(len(testCases)):
                contEmotes += buscarEmotes(emoticons, testCases[i])
            print(contEmotes)
        else:
            continuar = False

def partirNumeros(msj):
    cont = 0
    pos = [0, 0]
    for i in range(len(msj)):
        if msj[i] == " ":
            pos[0] = int(msj[: i])
            cont = i+1
    pos[1] = int(msj[cont: ])
    return pos


def insertarOrdenado(lista, palabra, left, right):
    if len(lista) == 0:
        lista.append(palabra)
        return lista
    else:
        mid = int(left + ((right-left)/2))
        if left >= right:
            if len(lista[left]) > len(palabra):
                lista.insert(left, palabra)
                return lista
            else:
                if right+1 == len(lista):
                    lista.append(palabra)
                else:
                    lista.insert(right+1, palabra)
                return lista
        else:
            if len(lista[mid]) > len(palabra):
                return insertarOrdenado(lista, palabra, left, mid-1)
            else:
                return insertarOrdenado(lista, palabra, mid+1, right)

def buscarEmotes(emoticons, text):
    parar = False
    cont = 0
    i = 0
    while(i < len(text) and not parar):
        j = 0
        while(j < len(emoticons) and not parar):
            if i+len(emoticons[j]) <= len(text):
                if text[i: i + len(emoticons[j])] == emoticons[j]:
                    text = text[: i] + text[i + len(emoticons[j]):]
                    j =- 1
                    cont += 1
                elif j == len(emoticons)-1:
                    i += 1
            elif j == len(emoticons)-1:
                parar = True
            j += 1
    return cont

if __name__ == '__main__':
    main()