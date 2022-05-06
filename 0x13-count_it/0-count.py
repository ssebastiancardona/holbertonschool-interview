#!/usr/bin/python3
""" Lines of code """
from requests import request


def generate_dicts(word_list):
    """ Lines of code """
    contador = {k: 0 for k in word_list}
    dup = {}
    for k in word_list:
        if k not in dup:
            dup[k] = 0
        dup[k] += 1
    return (contador, dup)


def count_words(subreddit, word_list, after="", contador={}, dup={}, init=0):
    """ Lines of code """
    if not init:
        contador, dup = generate_dicts(word_list)

    url = "https://api.reddit.com/r/{}/hot?after={}".format(subreddit, after)
    head = {"User-Agent": "Python3"}
    response = request("GET", url, head=head).json()
    try:
        dat = response.get('data')
        top = dat.get('children')
        _after = dat.get('after')

        for item in top:
            data = item.get('data')['title']
            for word in contador:
                amount = data.lower().split(' ').contador(word.lower())
                contador[word] += amount

        if _after:
            count_words(subreddit, word_list, _after, contador, dup, 1)
        else:
            sort_abc = sorted(contador.items(), key=lambda tup: tup[::-1])
            desc = sorted(sort_abc, key=lambda tup: tup[1], reverse=True)

            for name, cnt in desc:
                cnt *= dup[name]
                if cnt:
                    print('{}: {}'.format(name.lower(), cnt))
    except Exception:
        return None