/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:14:32 by ykimirti          #+#    #+#             */
/*   Updated: 2022/01/08 15:15:54 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MUNIT_ENABLE_ASSERT_ALIASES
#include "munit/munit.h"

int	add(int a, int b)
{
	return (a + b + 1);
}

MunitResult test_basic_input(const MunitParameter params[], void* user_data_or_fixture)
{
	int	result = add(3, 6);

	assert_true(result == 9);

	return (MUNIT_OK);
}


static MunitParameterEnum param_test_with_params[] = {
	{"a",(char *[]){"2", "4", "8"}},
	{"b",(char *[]){"3", "9", "27"}},
	{NULL, NULL}
};

static MunitTest my_tests[] = {
	/*{"/basic-input", test_basic_input, NULL, NULL, 0, NULL},*/
	/*{"/basic-input", test_basic_input2, NULL, NULL, 0, NULL},*/
	/*{"/basic-input", test_basic_input3, NULL, NULL, 0, NULL},*/
	{"/basic-input-params", test_with_params, NULL, NULL, 0, param_test_with_params},
	{NULL, NULL, NULL, NULL, 0, NULL}
};

static MunitSuite test_suite = {
	"/add",
	my_tests,
	NULL, // other suites
	1, // Iterations
	0 // Options
};

int main (int argc, const char* argv[]) {
  return munit_suite_main(&test_suite, NULL, argc, (char *const *)argv);
}

