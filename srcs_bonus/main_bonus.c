/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicetetu <atetu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 16:42:15 by alicetetu         #+#    #+#             */
/*   Updated: 2020/04/28 16:18:50 by alicetetu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct		t_list{
	void		*data;
	struct t_list	*next;
}			s_list;

int	ft_atoi_base(char *str, char *base);
void	ft_list_push_front(s_list **begin_list, void *data);
int	ft_list_size(s_list *begin_list);
void	ft_list_sort(s_list **begin_list, int (*cmp)());
int	ft_strcmp(const char *s1, const char *s2);
void	ft_list_remove_if(s_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));
void	free_fct(void *str);

void	free_fct(void *str)
{
	if (str)
		free(str);
}

int main ()
{
	s_list	*first_element;
	s_list	*ptr;
	s_list	**begin;
	char	*data;

	s_list	one;
	s_list	two;
	s_list	three;
	s_list	four;
	s_list	five;
	s_list	six;

	one.next = &two;
	two.next = &three;
	three.next = &four;
	four.next = &five;
	five.next = &six;
	six.next = NULL;

	one.data = malloc(sizeof(void *) * 2);
	strcpy(one.data, "9");
	two.data = malloc(sizeof(void *) * 2);
	strcpy(two.data, "5");
	three.data = malloc(sizeof(void *) * 2);
	strcpy(three.data, "4");
	four.data = malloc(sizeof(void *) * 2);
	strcpy(four.data, "4");
	five.data = malloc(sizeof(void *) * 2);
	strcpy(five.data, "3");
	six.data = malloc(sizeof(void *) * 2);
	strcpy(six.data, "2");



	printf("\n\n-----------------------FT_ATOI_BASE-------------------------\n\n");fflush(stdout);

	printf("Test 1:   -----125, base 10 : %d  ->expected result = -125\n", ft_atoi_base("    -----125", "0123456789"));
	printf("Test 2:   ++-+--125, base 10 : %d  ->expected result = -125\n", ft_atoi_base("    ++-+--125", "0123456789"));
	printf("Test 3: 456sshd, base 10 : %d  -> expected result = 456\n", ft_atoi_base("456sshd", "0123456789"));
	printf("Test 4:   ++-+--12589, base 16 : %d  -> expected result = -75145\n", ft_atoi_base("    ++-+--12589", "0123456789abcdef"));
	printf("Test 5: dc67, base 16 : %d  -> expected result = 56423\n", ft_atoi_base("dc67", "0123456789abcdef"));
	printf("Test 6: 0111110111110, base 2 : %d  -> expected result = 4030\n", ft_atoi_base("0111110111110", "01"));
	printf("Test 7: 456, base \"01 23456789\" : %d  -> expected result = 0\n", ft_atoi_base("456", "01 23456789"));
	printf("Test 8: 456, base \"0123456789+\" : %d  -> expected result = 0\n", ft_atoi_base("456", "0123456789+"));
	printf("Test 9: 456, base \"-0123456789\" : %d  -> expected result = 0\n", ft_atoi_base("456", "-0123456789"));
	printf("Test 10: 456, base \"01234\\n56789\" : %d  -> expected result = 0\n", ft_atoi_base("456", "01234\n56789"));
	printf("Test 11: 456, base \"01239456789\" : %d  -> expected result = 0\n", ft_atoi_base("456", "001234956789"));
	printf("Test 12: 456, base NULL : %d -> expected result = 0\n", ft_atoi_base("456", NULL));

//Segfault cases
//	printf("Test 13: NULL, base 10 : %d\n", ft_atoi_base(NULL, "01234956789"));
//	printf("atoi: %d\n", atoi(NULL));

	printf("\n\n-----------------------FT_LIST_PUSH_FRONT-------------------------\n\n");fflush(stdout);

	printf("Initial list with 6 elements ('one', 'two', 'three', 'four', five', 'six')\n");fflush(stdout);
	printf("Respective values of '*data': '9', '5', '4', '4', '3', '2')\n");fflush(stdout);
	ptr = &one;
	printf("Address of the first element of the list (equal to ptr): %p\n", ptr);fflush(stdout);
	if (!(data = malloc(sizeof(void *) * 2)))
		return (-1);
	strcpy(data, "8");
	ft_list_push_front(&ptr, data);
	printf("Data = 8\n\n");fflush(stdout);
	printf("After application of ft_list_push_front(&ptr, *data):\n");fflush(stdout);
	printf("-> address of the new first element of the list (value of ptr): %p\n", ptr);fflush(stdout);
	printf("-> address of *next in the new first element of the list (corresponding to the initial addres of 'one'): %p\n", ptr->next);fflush(stdout);
	printf("-> value of data in the new first element of the list: %s\n", ptr->data);fflush(stdout);
	printf("\nIf ptr = NULL, data 3\n");fflush(stdout);
	first_element = NULL;
	begin = &first_element;
	strcpy(data, "3");
	ft_list_push_front(begin, data);
	ptr = *begin;
	printf("new first_element: %p\n", *begin);fflush(stdout);
	printf("next de first_element: %p\n", ptr->next);fflush(stdout);
	printf("data de first_element: %s\n", ptr->data);fflush(stdout);
	free(ptr->data);
	
	printf("\n\n-----------------------FT_LIST_SIZE-------------------------\n\n");fflush(stdout);

	printf("ft_list_size(&one) = %d\n", ft_list_size(&one));fflush(stdout);
	printf("ft_list_size(&three) = %d\n", ft_list_size(&three));fflush(stdout);
	printf("ft_list_size(&six) = %d\n", ft_list_size(&six));fflush(stdout);
	printf("ft_list_size(NULL) = %d\n", ft_list_size(NULL));fflush(stdout);

	
	printf("\n\n-----------------------FT_LIST_SORT-------------------------\n\n");fflush(stdout);

	printf("Initial values of *data when reading the list\n");fflush(stdout);
	first_element = &one;
	while (first_element != NULL)
	{
		printf("%s  ", first_element->data);fflush(stdout);
		first_element = first_element->next;fflush(stdout);
	}
	first_element = &one;
	printf("\n\nNew values of *data after ft_list_sort\n");fflush(stdout);
	ft_list_sort(&first_element, &ft_strcmp);
	while (first_element != NULL)
	{
		printf("%s  ", first_element->data);fflush(stdout);
		first_element = first_element->next;
	}
	printf("\n");fflush(stdout);
	
	printf("\n\n-----------------------FT_LIST_REMOVE_IF-------------------------\n\n");fflush(stdout);

	first_element = &one;
	ft_list_remove_if(&first_element, "4", &ft_strcmp, &free_fct);
	printf("Remove '4':\n");fflush(stdout);
	while (first_element != NULL)
	{
		printf("%s  ", first_element->data);fflush(stdout);
		first_element = first_element->next;
	}
	printf("\n");fflush(stdout);

	first_element = &one;
	ft_list_remove_if(&first_element, "9", &ft_strcmp, &free_fct);
	printf("Remove '9':\n");
	while (first_element != NULL)
	{
		printf("%s  ", first_element->data);
		first_element = first_element->next;
	}
	printf("\n");
}
