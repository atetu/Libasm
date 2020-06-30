/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicetetu <atetu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 16:41:51 by alicetetu         #+#    #+#             */
/*   Updated: 2020/04/28 13:36:31 by alicetetu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>

size_t	ft_strlen(const char *);
char	*ft_strcpy(char *dst, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t	ft_read(int fildes, void *buf, size_t nbyte);
char	*ft_strdup(const char *s1);
int		ft_atoi_base(char *str, char *base);
void	test_write(char *string, int len);
void	test_error_write(int fd, char *string, int len);

int main(void)
{
	char	dst[100];
	ssize_t	ret;
	char	*error;
	char	buf1[100];
	char	buf2[100];
	int		fd;
	ssize_t	ret1;
	ssize_t	ret2;

	ret = 0;
	error = NULL;

	printf("---------------------FT_STRLEN-----------------------\n\n");fflush(stdout);
	printf("1. str = hello\n");
	printf("result with ft_strlen = %lu\n", ft_strlen("hello"));fflush(stdout);
	printf("expected result (strlen) = %lu\n\n", strlen("hello"));fflush(stdout);

	printf("2. str = 52      000lh\n");fflush(stdout);
	printf("result with ft_strlen = %lu\n", ft_strlen("52      000lh"));fflush(stdout);
	printf("expected result (strlen) = %lu\n\n", strlen("h52      000l"));fflush(stdout);

	printf("3. str = ""\n");fflush(stdout);
	printf("result with ft_strlen = %lu\n", ft_strlen(""));fflush(stdout);
	printf("expected result (strlen) = %lu\n\n", strlen(""));fflush(stdout);

// 	Segfault case
//	printf("4. str = NULL\n");fflush(stdout);
//	printf("result with ft_strlen = %lu\n", ft_strlen(NULL));fflush(stdout);
//	printf("expected result (strlen) = %lu\n\n", strlen(NULL));fflush(stdout);
	
	printf("---------------------FT_STRCPY-----------------------\n\n");fflush(stdout);
	printf("1. str = hello\n");fflush(stdout);
	printf("result with ft_strcpy = %s\n", ft_strcpy(dst, "hello"));fflush(stdout);
	memset(dst, 0, 100);
	printf("expected result (strcpy) = %s\n\n", strcpy(dst, "hello"));fflush(stdout);
	memset(dst, 0, 100);

	printf("2. str = ""\n");fflush(stdout);
	printf("result with ft_strcpy = %s\n", ft_strcpy(dst, ""));fflush(stdout);
	memset(dst, 0, 100);
	printf("expected result (strcpy) = %s\n\n", strcpy(dst, ""));fflush(stdout);
	memset(dst, 0, 100);
	
	printf("3. str = :|()*&jdcn\n");fflush(stdout);
	printf("result with ft_strcpy = %s\n", ft_strcpy(dst, ":|()*&jdcn"));fflush(stdout);
	memset(dst, 0, 100);
	printf("expected result (strcpy) = %s\n\n", strcpy(dst, ":|()*&jdcn"));fflush(stdout);
	memset(dst, 0, 100);

// 	Segfault case
//	printf("4. str = NULL\n");
//	printf("result with ft_strcpy = %s\n", ft_strcpy(dst, NULL));
//	memset(dst, 0, 100);
//	printf("expected result (strlen) = %s\n\n", strcpy(dst, NULL));
//	memset(dst, 0, 100);

	printf("---------------------FT_STRCMP-----------------------\n\n");fflush(stdout);

	
	printf("1. str1 = hello - str2 = hella\n");fflush(stdout);
	printf("result with ft_strcmp = %d\n", ft_strcmp("hello", "hella"));fflush(stdout);
	printf("expected result (strcmp) = %d\n\n", strcmp("hello", "hella"));fflush(stdout);
	printf("1. str1 = hella - str2 = hello\n");fflush(stdout);
	printf("result with ft_strcmp = %d\n", ft_strcmp("hella", "hello"));fflush(stdout);
	printf("expected result (strcmp) = %d\n\n", strcmp("hella", "hello"));fflush(stdout);


	printf("2. str1 = hel - str2 = hello\n");fflush(stdout);
	printf("result with ft_strcmp = %d\n", ft_strcmp("hel", "hello"));fflush(stdout);
	printf("expected result (strcmp) = %d\n\n", strcmp("hel", "hello"));fflush(stdout);

	printf("3. str1 = hello - str2 = hel\n");fflush(stdout);
	printf("result with ft_strcmp = %d\n", ft_strcmp("hello", "hel"));fflush(stdout);
	printf("expected result (strcmp) = %d\n\n", strcmp("hello", "hel"));fflush(stdout);

	printf("4. str1 = "" - str2 = hello\n");fflush(stdout);
	printf("result with ft_strcmp = %d\n", ft_strcmp("", "hello"));fflush(stdout);
	printf("expected result (strcmp) = %d\n\n", strcmp("", "hello"));fflush(stdout);

	printf("5. str1 = hello - str2 = ""\n");fflush(stdout);
	printf("result with ft_strcmp = %d\n", ft_strcmp("hello", ""));fflush(stdout);
	printf("expected result (strcmp) = %d\n\n", strcmp("hello", ""));fflush(stdout);

	printf("6. str1 = "" - str2 = ""\n");fflush(stdout);
	printf("result with ft_strcmp = %d\n", ft_strcmp("", ""));fflush(stdout);
	printf("expected result (strcmp) = %d\n\n", strcmp("", ""));fflush(stdout);

//	Segfault cases
//	printf("7. str1 = NULL - str2 = hello\n");
//	printf("result with ft_strcmp = %d\n", ft_strcmp(NULL, "hello"));
//	printf("expected result (strcmp) = %d\n\n", strcmp(NULL, "hello"));

//	printf("8. str1 = hello - str2 = NULL\n");
//	printf("result with ft_strcmp = %d\n", ft_strcmp("hello", NULL));
//	printf("expected result (strcmp) = %d\n\n", strcmp("hello", NULL));

//	printf("9. str1 = NULL - str2 = NULL\n");fflush(stdout);
//	printf("result with ft_strcmp = %d\n", ft_strcmp(NULL, NULL));
//	printf("expected result (strcmp) = %d\n\n", strcmp(NULL, NULL));


	printf("---------------------FT_WRITE-----------------------\n\n");fflush(stdout);

	printf("1. str1 = hello / 5\n");fflush(stdout);
	test_write("hello", 5);
	printf("\n2. str2 = hello / 6\n");fflush(stdout);
	test_write("hello", 6);
	printf("\n3. str3 = hello / 0\n");fflush(stdout);
	test_write("hello", 0);
	printf("\n4. str4 = "" / 0\n");fflush(stdout);
	test_write("", 0);
	printf("\n5. str5 = NULL / 0\n");fflush(stdout);
	test_write(NULL, 0);
	
	printf("\nERROR EXAMPLE - WRONG FD\n");fflush(stdout);
	printf("\nfd: 24 / str6 = hello / nbytes: 5\n\n");fflush(stdout);
	test_error_write(24, "hello", 5);


	printf("\n---------------------FT_READ-----------------------\n\n");fflush(stdout);
	
	printf("1. 20 characters from existing file\n"); fflush(stdout);
	fd = open("srcs/test", O_RDONLY);
	ret1 = ft_read(fd, buf1, 20);
	printf("ft_read: %s\n", buf1);fflush(stdout);
	printf("ret de ft_read: %zu\n", ret1);fflush(stdout);
	close(fd);
	fd = open("srcs/test", O_RDONLY);
	ret2 = read(fd, buf2, 20);
	printf("read: %s\n", buf2);fflush(stdout);fflush(stdout);
	printf("ret de read: %zu\n\n", ret2);fflush(stdout);
	
	printf("2. 20 characters from non existing file\n"); fflush(stdout);
	memset(buf1, 0, 100);
	memset(buf2, 0, 100);
	errno = 0;
	fd = open("example", O_RDONLY);
	ret1 = ft_read(fd, buf1, 20);
	printf("ft_read: %s\n", buf1);fflush(stdout);
	printf("ret of ft_read: %zu\n", ret1);fflush(stdout);
	printf("errno of ft_read: %d\n", errno);fflush(stdout);
	printf("strerror of ft_read: %s\n", strerror(errno));fflush(stdout);
	close(fd);
	errno = 0;
	fd = open("example", O_RDONLY);
	ret2 = read(fd, buf2, 20);
	printf("read: %s\n", buf2);fflush(stdout);
	printf("ret of read: %zu\n", ret2);fflush(stdout);
	printf("errno of read: %d\n", errno);fflush(stdout);
	printf("strerror of read: %s\n\n", strerror(errno));fflush(stdout);

	printf("3. Negative number of characters\n"); fflush(stdout);
	memset(buf1, 0, 100);
	memset(buf2, 0, 100);
	errno = 0;
	fd = open("srcs/test", O_RDONLY);
	ret1 = ft_read(fd, buf1, -10);
	printf("ft_read: %s\n", buf1);fflush(stdout);
	printf("ret of ft_read: %zu\n", ret1);fflush(stdout);
	printf("errno of ft_read: %d\n", errno);fflush(stdout);
	printf("strerror of ft_read: %s\n", strerror(errno));fflush(stdout);
	close(fd);
	errno = 0;
	fd = open("srcs/test", O_RDONLY);
	ret2 = read(fd, buf2, -10);
	printf("read: %s\n", buf2);fflush(stdout);
	printf("ret of read: %zu\n", ret2);fflush(stdout);
	printf("errno of read: %d\n", errno);fflush(stdout);
	printf("strerror of read: %s\n", strerror(errno));fflush(stdout);

	printf("\n---------------------FT_STRDUP-----------------------\n\n");fflush(stdout);
	
	printf("1. original string = hello\n");fflush(stdout);
	printf("copy with ft_strdup : %s\n", ft_strdup("hello"));fflush(stdout);
	printf("copy with strdup: %s\n", strdup("hello"));fflush(stdout);
	
	printf("\n2. original string = ""\n");fflush(stdout);
	printf("copy with ft_strdup : %s\n", ft_strdup(""));fflush(stdout);
	printf("copy with strdup: %s\n", strdup(""));fflush(stdout);

// Sgefault case
//	printf("3. original string = NULL\n");fflush(stdout);
//	printf("copy with ft_strdup : %s\n", ft_strdup(NULL));fflush(stdout);
//	printf("copy with strdup: %s\n", strdup(NULL));fflush(stdout);
}

void test_write(char *string, int len)
{
	size_t ret;
	size_t ret2;

	write (1, "ft_write: ", 10);
	ret = ft_write(1, string, len);
	write (1, "\nwrite: ", 8);
	ret2 = write(1, string, len);
	write (1, "\n", 1);

	printf("ft_write: %zu\n", ret);fflush(stdout);
	printf("write: %zu\n", ret2);fflush(stdout);
}


void	test_error_write(int fd, char *string, int len)
{
	size_t ret;
	char *error;

	errno = 0;
	ret = 0;
	error = NULL;
	ret = ft_write(fd, string, len);
	printf("result of ft_write : %zd\n", ret);fflush(stdout);
	printf("errno of ft_write = %d\n", errno); fflush(stdout);
	error = strerror(errno);
	printf("strerror of ft_write = %s\n", error); fflush(stdout);
	errno = 0;
	ret = 0;
	ret = write(fd, string, len);
	printf("result of write: %zd \n", ret); fflush(stdout);
	printf("errno of write = %d\n", errno); fflush(stdout);
	error = strerror(errno);
	printf("strerror of write = %s\n", error); fflush(stdout);
}
