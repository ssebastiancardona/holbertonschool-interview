#!/usr/bin/python3
""" Lines of code """
from requests import request


def generate_dicts(word_list):
    """ Lines of code """
    contador = {k: 0 for k in word_list}
    dupo = {}
    for k in word_list:
        if k not in dupo:
            dupo[k] = 0
        dupo[k] += 1
    return (contador, dupo)


def count_words(subreddit, word_list, after="", count={}, dup={}, init=0):
    """ Lines of code """
    if not init:
        count, dup = generate_dicts(word_list)

    url = "https://api.reddit.com/r/{}/hot?after={}".format(subreddit, after)
    headers = {"User-Agent": "Python3"}
    response = request("GET", url, headers=headers).json()
    try:
        dat = response.get('data')
        top = dat.get('children')
        _after = dat.get('after')

        for item in top:
            dat = item.get('data')['title']
            for word in count:
                amount = dat.lower().split(' ').count(word.lower())
                count[word] += amount

        if _after:
            count_words(subreddit, word_list, _after, count, dup, 1)
        else:
            sort_abc = sorted(count.items(), key=lambda tup: tup[::-1])
            desco = sorted(sort_abc, key=lambda tup: tup[1], reverse=True)

            for name, cnt in desco:
                cnt *= dup[name]
                if cnt:
                    print('{}: {}'.format(name.lower(), cnt))
    except Exception:
        return None