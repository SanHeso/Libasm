#include "libasm.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

void	test_strlen(void)
{
	char	*t_len = "123456";
	char	*t_len1 = "";
	char	*t_len2 = "rngirhgiu43oy  ctio4yc34pty7gc45325#$@_4gregicgere";
	char	*t_len3 = "rngirhgiu43oyctio4hct34pty7gc4c\rt45324greigcgecgre";

	printf("[1] Short string [%s]\n", t_len);
	printf("ft_strlen: [%lu]\n", ft_strlen(t_len));
	printf("strlen:    [%lu]\n", strlen(t_len));
	printf("\n[2] Empty string [%s]\n", t_len1);
	printf("ft_strlen: [%lu]\n", ft_strlen(t_len1));
	printf("strlen:    [%lu]\n", strlen(t_len1));
	printf("\n[3] Long string [%s]\n", t_len2);
	printf("ft_strlen: [%lu]\n", ft_strlen(t_len2));
	printf("strlen:    [%lu]\n", strlen(t_len2));
	printf("\n[4] Long string(spec. symbols) [%s]\n", t_len3);
	printf("ft_strlen: [%lu]\n", ft_strlen(t_len3));
	printf("strlen:    [%lu]\n", strlen(t_len3));
}

void	test_strcpy(void)
{
	char	*t_len = "123456";
	char	*t_len1 = "rngirhgiu43oy  ctio4ct34pty7gc4c25#$@_4gregcigecge";
	char	*dst1 = malloc(sizeof(char) * 100);
	char	*dst2 = malloc(sizeof(char) * 100);
	char	*or_dst1 = malloc(sizeof(char) * 100);
	char	*or_dst2 = malloc(sizeof(char) * 100);

	printf("[1] Short string [%s]\n", t_len);
	printf("ft_strcpy: [%s]\n", ft_strcpy(dst1, t_len));
	printf("strcpy:    [%s]\n", strcpy(or_dst1, t_len));
	printf("\n[2] Long string [%s]\n", t_len1);
	printf("ft_strcpy: [%s]\n", ft_strcpy(dst2, t_len1));
	printf("strcpy:    [%s]\n", strcpy(or_dst2, t_len1));
	free(dst1);
	free(dst2);
	free(or_dst1);
	free(or_dst2);
}

void	test_strcmp(void)
{
	char	*t_len = "123456";
	char	*t_len1 = "rngirhgiu43oy  cti3yct34pty7gc4c5#$@_4gregcgeicgre";
	char	*cmp_len = "122226";
	char	*cmp_len1 = "rngirhgiu43oy       ct34pty7gc4c5#$@_4gregcgeicgre";

	printf("[1] Short, equal string [%s]\n", t_len);
	printf("ft_strcmp: [%d]\n", ft_strcmp(t_len, t_len));
	printf("strcmp:    [%d]\n", strcmp(t_len, t_len));
	printf("\n[2] Long, equal string [%s]\n", t_len1);
	printf("ft_strcmp: [%d]\n", ft_strcmp(t_len1, t_len1));
	printf("strcmp:    [%d]\n", strcmp(t_len1, t_len1));
	printf("\n[3] Short, not equal string [ %s ] ; [ %s ]\n", t_len, cmp_len);
	printf("ft_strcmp: [%d]\n", ft_strcmp(t_len, cmp_len));
	printf("strcmp:    [%d]\n", strcmp(t_len, cmp_len));
	printf("\n[4] Long, not equal string [ %s ] ; [ %s ]\n", t_len1, cmp_len1);
	printf("ft_strcmp: [%d]\n", ft_strcmp(t_len1, cmp_len1));
	printf("strcmp:    [%d]\n", strcmp(t_len1, cmp_len1));
}

void	test_write(void)
{
	char	*t_len = "123456";
	char	*t_len1 = "rngirhgiu43oy  cti3yct34pty7gc4c5#$@_4gregcgecgre";

	printf("[1] Short string [%s]\n", t_len);
	printf(" - ft_write");
	ft_write(1, t_len, ft_strlen(t_len));
	printf("\n - write");
	write(1, t_len, ft_strlen(t_len));
	printf("\n\n[2] Long string [%s]\n", t_len1);
	printf(" - ft_write");
	ft_write(1, t_len1, ft_strlen(t_len1));
	printf("\n - write");
	write(1, t_len1, ft_strlen(t_len1));
	printf("\n\n[3] Negative descriptor\n");
	printf("ft_ = %zd\n", ft_write(-1, t_len, ft_strlen(t_len)));
	printf("Orig = %zd\n", write(-1, t_len, ft_strlen(t_len)));
	printf("\n[4] Wrong descriptor\n");
	printf("ft_ = %zd\n", ft_write(10, t_len, ft_strlen(t_len)));
	printf("Orig = %zd\n", write(10, t_len, ft_strlen(t_len)));
}

void	test_read(void)
{
	char	*t_len = "123456";
	int		fd;
	char	buf[15], buff[15];

	printf("[1] Reading from file\n");
	if (!(fd = open("test.txt", O_RDONLY, O_CREAT)))
		exit(0);
	while (ft_read(fd, buf, 15) > 0)
		ft_write(0, buf, 15);
	printf("\n\n[2] Negative descriptor\n");
	printf("ft_ = %zd\n", ft_read(-1, buf, 14));
	printf("Orig = %zd\n", read(-1, buff, 14));
	printf("\n[3] Wrong descriptor\n");
	printf("ft_ = %zd\n", ft_read(30, buf, 14));
	printf("Orig = %zd\n", read(30, buff, strlen(t_len)));
	printf("\n[4] Reading from console\n");
	bzero(buf, sizeof(char) * 15);
	ft_write(0, buf, ft_read(0, buf, 15));
}

void	test_strdup(void)
{
	char	*str;
	char	*str1;

	printf("[1] Short string [tet a tet]\n");
	str = ft_strdup("tet a tet");
	printf("ft_ string: %s\n", str);
	str1 = strdup("tet a tet");
	printf("Orig string: %s\n", str1);
	printf("\n[2] Empty string []\n");
	str = ft_strdup("");
	printf("ft_ string: %s\n", str);
	str1 = strdup("");
	printf("Orig string: %s\n", str1);
	printf("\n[3] Long string(spec. symbols)\n");
	str = ft_strdup("fesmcrixw\nremwoifjerf\0r12345");
	printf("ft_ string: %s\n", str);
	str1 = strdup("fesmcrixw\nremwoifjerf\0r12345");
	printf("Orig string: %s\n", str1);
}

int	main(void)
{
	printf("~~~~~~~~~~~~~~~~| TEST FT_STRLEN START |~~~~~~~~~~~~~~~~\n");
	test_strlen();
	printf("~~~~~~~~~~~~~~~~| TEST FT_STRLEN END |~~~~~~~~~~~~~~~~\n\n\n");
	printf("~~~~~~~~~~~~~~~~| TEST FT_STRCPY START |~~~~~~~~~~~~~~~~\n");
	test_strcpy();
	printf("~~~~~~~~~~~~~~~~| TEST FT_STRCPY END |~~~~~~~~~~~~~~~~\n\n\n");
	printf("~~~~~~~~~~~~~~~~| TEST FT_STRCMP START |~~~~~~~~~~~~~~~~\n");
	test_strcmp();
	printf("~~~~~~~~~~~~~~~~| TEST FT_STRCMP END |~~~~~~~~~~~~~~~~\n\n\n");
	printf("~~~~~~~~~~~~~~~~| TEST FT_WRITE START |~~~~~~~~~~~~~~~~\n");
	test_write();
	printf("~~~~~~~~~~~~~~~~| TEST FT_WRITE END |~~~~~~~~~~~~~~~~\n\n\n");
	printf("~~~~~~~~~~~~~~~~| TEST FT_READ START |~~~~~~~~~~~~~~~~\n");
	test_read();
	printf("~~~~~~~~~~~~~~~~| TEST FT_READ END |~~~~~~~~~~~~~~~~\n\n\n");
	printf("~~~~~~~~~~~~~~~~| TEST FT_STRDUP START |~~~~~~~~~~~~~~~~\n");
	test_strdup();
	printf("~~~~~~~~~~~~~~~~| TEST FT_STRDUP END |~~~~~~~~~~~~~~~~\n\n\n");
}
