/*
** my_hashmap_rehash.c for libmy in /home/benji_epitech/workdir/libmy/lib/my/src/hash
**
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
**
** Started on  Wed Nov 01 17:43:48 2017 Benjamin Viguier
** Last update Wed Nov 01 20:08:12 2017 Benjamin Viguier
*/

#include "libmy_hash.h"

t_hashmap_result    __libmy_hashmap_check_for_rehash(t_hashmap *hm)
{
    if ((size_t) ((float) hm->size * hm->load_factor) < hm->used)
        return (hashmap_rehash(hm, (size_t) ((double) hm->size * 1.30)));
    else if (hm->size > hm->initial_size && hm->used < hm->size / 4)
        return (hashmap_rehash(hm, (size_t) ((double) hm->size * 0.70)));
    return (HM_SUCCESS);
}

static t_hashmap_result __libmy_hashmap_replace_elem(t_hashmap *hm,
                                                    t_hashmap_element *element)
{
    t_hashmap_element   elem;

    elem = (t_hashmap_element) {
        .key = element->key,
        .key_len = element->key_len,
        .value = element->value,
        .value_len = element->value_len
    };
    return (hashmap_push(hm, &elem));
}

static t_hashmap_result __libmy_hashmap_replace_clist(t_hashmap *hm, t_clist *list)
{
    t_clist_elm         *current;
    t_hashmap_result    replace_result;

    current = list;
    while (current)
    {
        replace_result = __libmy_hashmap_replace_elem(hm, current->ptr);
        if (replace_result & HM_ERROR)
            return (replace_result);
        current = CLIST_NEXT(list, current);
    }
    clist_free(list);
    return (HM_SUCCESS);
}

t_hashmap_result        hashmap_rehash(t_hashmap *hm, size_t new_size)
{
    t_bucket_elem       *old_bucket;
    size_t              old_size;
    t_bucket_elem       *current;
    t_hashmap_result    replace_result;
    
    if (new_size < hm->used)
        return (HM_SUCCESS);
    old_bucket = hm->bucket;
    if (!(hm->bucket = malloc(sizeof(t_bucket_elem) * new_size)))
        return (HM_ERROR | HM_OUTOFMEM);
    old_size = hm->size;
    current = hm->bucket;
    hm->size = new_size;
    while (old_size--) {
        if (current->type == HM_ELEMENT)
            replace_result = __libmy_hashmap_replace_elem(hm, &(current->value.elem));
        else if (current->type == HM_CLIST)
            replace_result = __libmy_hashmap_replace_clist(hm, current->value.clist);
        else
            replace_result = HM_SUCCESS;
        if (replace_result & HM_ERROR)
            return (replace_result);
    }
    free(old_bucket);
    return (HM_SUCCESS);
}