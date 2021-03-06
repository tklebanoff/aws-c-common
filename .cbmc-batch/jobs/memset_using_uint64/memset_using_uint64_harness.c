/*
 * Copyright 2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"). You may not use
 * this file except in compliance with the License. A copy of the License is
 * located at
 *
 *     http://aws.amazon.com/apache2.0/
 *
 * or in the "license" file accompanying this file. This file is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
 * implied. See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <proof_helpers/utils.h>
#include <stddef.h>

void *memset_impl(void *dst, int c, size_t n);
void *memset_using_uint64_impl(void *dst, int c, size_t n);

/*
 * Check that the optimized version of memset is memory safe
 * And that it matches the naive version
 */
void memset_using_uint64_harness() {

    short d1[MAX];
    short d2[MAX];
    int c;
    unsigned size;
    __CPROVER_assume(size < MAX);
    memset_impl(d1, c, size);
    memset_using_uint64_impl(d2, c, size);
    assert_bytes_match(d1, d2, size);
    assert_all_bytes_are(d2, c, size);
}
