/*
   GSS-PROXY

   Copyright (C) 2011 Red Hat, Inc.
   Copyright (C) 2011 Simo Sorce <simo.sorce@redhat.com>

   Permission is hereby granted, free of charge, to any person obtaining a
   copy of this software and associated documentation files (the "Software"),
   to deal in the Software without restriction, including without limitation
   the rights to use, copy, modify, merge, publish, distribute, sublicense,
   and/or sell copies of the Software, and to permit persons to whom the
   Software is furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in
   all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
   THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
   FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
   DEALINGS IN THE SOFTWARE.
*/

#ifndef _GSSAPI_GPM_H_
#define _GSSAPI_GPM_H_

#include "config.h"
#include <stdint.h>
#include <stdbool.h>
#include <errno.h>
#include <gssapi/gssapi.h>
#include "rpcgen/gp_rpc.h"
#include "rpcgen/gss_proxy.h"
#include "src/gp_common.h"
#include "src/gp_conv.h"

int gpm_make_call(int proc, union gp_rpc_arg *arg, union gp_rpc_res *res);
void gpm_free_xdrs(int proc, union gp_rpc_arg *arg, union gp_rpc_res *res);

OM_uint32 gpm_release_name(OM_uint32 *minor_status,
                           gss_name_t *input_name);
OM_uint32 gpm_release_buffer(OM_uint32 *minor_status,
                             gss_buffer_t buffer);

void gpm_save_status(gssx_status *status);

OM_uint32 gpm_display_status(OM_uint32 *minor_status,
                             OM_uint32 status_value,
                             int status_type,
                             const gss_OID mech_type,
                             OM_uint32 *message_context,
                             gss_buffer_t status_string);

OM_uint32 gpm_accept_sec_context(OM_uint32 *minor_status,
                                 gss_ctx_id_t *context_handle,
                                 gss_cred_id_t acceptor_cred_handle,
                                 gss_buffer_t input_token_buffer,
                                 gss_channel_bindings_t input_chan_bindings,
                                 gss_name_t *src_name,
                                 gss_OID *mech_type,
                                 gss_buffer_t output_token,
                                 OM_uint32 *ret_flags,
                                 OM_uint32 *time_rec,
                                 gss_cred_id_t *delegated_cred_handle);

OM_uint32 gpm_release_cred(OM_uint32 *minor_status,
                           gss_cred_id_t *cred_handle);

OM_uint32 gpm_delete_sec_context(OM_uint32 *minor_status,
                                 gss_ctx_id_t *context_handle,
                                 gss_buffer_t output_token);

OM_uint32 gpm_acquire_cred(OM_uint32 *minor_status,
                           const gss_name_t desired_name,
                           OM_uint32 time_req,
                           const gss_OID_set desired_mechs,
                           gss_cred_usage_t cred_usage,
                           gss_cred_id_t *output_cred_handle,
                           gss_OID_set *actual_mechs,
                           OM_uint32 *time_rec);

OM_uint32 gpm_add_cred(OM_uint32 *minor_status,
                       const gss_cred_id_t input_cred_handle,
                       const gss_name_t desired_name,
                       const gss_OID desired_mech,
                       gss_cred_usage_t cred_usage,
                       OM_uint32 initiator_time_req,
                       OM_uint32 acceptor_time_req,
                       gss_cred_id_t *output_cred_handle,
                       gss_OID_set *actual_mechs,
                       OM_uint32 *initiator_time_rec,
                       OM_uint32 *acceptor_time_rec);

OM_uint32 gpm_indicate_mechs(OM_uint32 *minor_status, gss_OID_set *mech_set);

#endif /* _GSSAPI_GPM_H_ */
