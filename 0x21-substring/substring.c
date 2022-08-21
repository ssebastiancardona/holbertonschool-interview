#include "substring.h"

/**
 * not_in - return 1 if 'q' not in array 'arr'
 * @arr: an array of ints
 * @len: the length of arr
 * @q: the value to check for
 * Return: 1 if value not found, else 0
 */
int not_in(int *arr, int len, int q)
{
	int j = 0;

	for (j = 0; j < len; j++)
	{
		if (arr[j] == q)
			return (0);
	}
	return (1);
}

/**
 * str_match - match word as a substring of str
 * @str: a string
 * @word: an array of words
 * Return: 1 if word is a substring of str, 0 otherwise
 */
int str_match(char const *str, char const *word)
{
	int j = 0;

	for (j = 0; *(word + j) != '\0'; j++)
	{
		if (*(str + j) != *(word + j))
			return (0);
	}
	return (1);
}

/**
 * full_match - find if a substring match occurs at a single location
 * @s: a string
 * @words: an array of words
 * @nb_words: the number of elements in parameter 'words'
 * @word_len: the length of each word
 * Return: 1 if a full match of a substring made of 'words' exists, 0 otherwise
 */
int full_match(char const *s, char const **words, int nb_words, int word_len)
{
	int *don;
	int don_len = 0;
	int found = 0;
	int match = 1;
	int j, k, l;
	int aint;

	don = malloc(sizeof(int) * nb_words);

	for (l = 0; l < nb_words; l++)
		don[l] = -1;

	for (j = 0; j < nb_words; j++)
	{
		found = 0;
		for (k = 0; k < nb_words; k++)
		{
			aint = not_in(don, don_len, k);
			if (aint && str_match((s + (j * word_len)), words[k]))
			{
				don[don_len] = k;
				don_len++;
				found = 1;
				break;
			}
		}
		if (found == 0)
		{
			match = 0;
			break;
		}
	}
	free(don);
	return (match);
}

/**
 * find_substring - find in 's' substrings made up of the words in 'words'
 * @s: a string
 * @words: an array of words
 * @nb_words: the number of elements in parameter 'words'
 * @n: AUX RETURN VALUE the number of elements in the returned array
 * Return: an array of starting indices of found substrings
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int *result;
	int str_len = 0;
	int word_len = 0;
	int i;

	*n = 0;
	if (s == NULL || words == NULL || *words == NULL || nb_words == 0)
		return (NULL);

	for (i = 0; s[i] != '\0'; i++)
		str_len++;
	for (i = 0; words[0][i] != '\0'; i++)
		word_len++;

	result = malloc(sizeof(int) * str_len);
	if (result == NULL)
		return (NULL);

	for (i = 0; *(s + i) != '\0'; i++)
	{
		if (full_match(s + i, words, nb_words, word_len))
		{
			result[*n] = i;
			*n = *n + 1;
		}
	}

	if (*n == 0)
	{
		free(result);
		return (NULL);
	}

	return (result);
}