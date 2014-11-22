/*
 * %CopyrightBegin%
 *
 * Copyright Ericsson AB 2005-2011. All Rights Reserved.
 *
 * The contents of this file are subject to the Erlang Public License,
 * Version 1.1, (the "License"); you may not use this file except in
 * compliance with the License. You should have received a copy of the
 * Erlang Public License along with this software. If not, it can be
 * retrieved online at http://www.erlang.org/.
 *
 * Software distributed under the License is distributed on an "AS IS"
 * basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See
 * the License for the specific language governing rights and limitations
 * under the License.
 *
 * %CopyrightEnd%
 */


#ifndef HIPE_PRIMOPS_H
#define HIPE_PRIMOPS_H

PRIMOP_LIST(am_suspend_msg, &nbif_suspend_msg)
PRIMOP_LIST(am_suspend_msg_timeout, &nbif_suspend_msg_timeout)
PRIMOP_LIST(am_suspend_0, &nbif_suspend_0)

PRIMOP_LIST(am_Plus, &nbif_add_2)
PRIMOP_LIST(am_Minus, &nbif_sub_2)
PRIMOP_LIST(am_Times, &nbif_mul_2)
PRIMOP_LIST(am_Div, &nbif_div_2)
PRIMOP_LIST(am_div, &nbif_intdiv_2)
PRIMOP_LIST(am_rem, &nbif_rem_2)
PRIMOP_LIST(am_bsl, &nbif_bsl_2)
PRIMOP_LIST(am_bsr, &nbif_bsr_2)
PRIMOP_LIST(am_band, &nbif_band_2)
PRIMOP_LIST(am_bor, &nbif_bor_2)
PRIMOP_LIST(am_bxor, &nbif_bxor_2)
PRIMOP_LIST(am_bnot, &nbif_bnot_1)

PRIMOP_LIST(am_gc_1, &nbif_gc_1)
PRIMOP_LIST(am_check_get_msg, &nbif_check_get_msg)
#ifdef ERTS_SMP
PRIMOP_LIST(am_atomic_inc, &nbif_atomic_inc)
PRIMOP_LIST(am_clear_timeout, &nbif_clear_timeout)
#endif
PRIMOP_LIST(am_select_msg, &nbif_select_msg)
PRIMOP_LIST(am_set_timeout, &nbif_set_timeout)
PRIMOP_LIST(am_rethrow, &nbif_rethrow)


PRIMOP_LIST(am_bs_get_integer_2, &nbif_bs_get_integer_2)
PRIMOP_LIST(am_bs_get_float_2, &nbif_bs_get_float_2)
PRIMOP_LIST(am_bs_get_binary_2, &nbif_bs_get_binary_2)
PRIMOP_LIST(am_bs_allocate, &nbif_bs_allocate)
PRIMOP_LIST(am_bs_reallocate, &nbif_bs_reallocate)
PRIMOP_LIST(am_bs_put_big_integer, &nbif_bs_put_big_integer)
PRIMOP_LIST(am_bs_put_small_float, &nbif_bs_put_small_float)
PRIMOP_LIST(am_bs_put_bits, &nbif_bs_put_bits)
PRIMOP_LIST(am_bs_utf8_size, &nbif_bs_utf8_size)
PRIMOP_LIST(am_bs_put_utf8, &nbif_bs_put_utf8)
PRIMOP_LIST(am_bs_get_utf8, &nbif_bs_get_utf8)
PRIMOP_LIST(am_bs_utf16_size, &nbif_bs_utf16_size)
PRIMOP_LIST(am_bs_put_utf16be, &nbif_bs_put_utf16be)
PRIMOP_LIST(am_bs_put_utf16le, &nbif_bs_put_utf16le)
PRIMOP_LIST(am_bs_get_utf16, &nbif_bs_get_utf16)
PRIMOP_LIST(am_bs_validate_unicode, &nbif_bs_validate_unicode)
PRIMOP_LIST(am_bs_validate_unicode_retract, &nbif_bs_validate_unicode_retract)

PRIMOP_LIST(am_cmp_2, &nbif_cmp_2)
PRIMOP_LIST(am_op_exact_eqeq_2, &nbif_eq_2)

PRIMOP_LIST(am_hipe_apply, &nbif_apply)
PRIMOP_LIST(am_find_na_or_make_stub, &nbif_find_na_or_make_stub)
PRIMOP_LIST(am_nonclosure_address, &nbif_nonclosure_address)

PRIMOP_LIST(am_conv_big_to_float, &nbif_conv_big_to_float)
PRIMOP_LIST(am_fclearerror_error, &nbif_fclearerror_error)

#if defined(__sparc__)
#include "hipe_sparc_primops.h"
#endif
#if defined(__i386__)
#include "hipe_x86_primops.h"
#endif
#if defined(__x86_64__)
#include "hipe_amd64_primops.h"
#endif
#if defined(__powerpc__) || defined(__ppc__) || defined(__powerpc64__)
#include "hipe_ppc_primops.h"
#endif
#if defined(__arm__)
#include "hipe_arm_primops.h"
#endif

#endif /* HIPE_PRIMOPS_H */
