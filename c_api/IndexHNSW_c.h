/**
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

// Copyright 2004-present Facebook. All Rights Reserved.
// -*- c++ -*-

#ifndef FAISS_INDEX_HNSW_C_H
#define FAISS_INDEX_HNSW_C_H

#include "Index_c.h"
#include "faiss_c.h"

#ifdef __cplusplus
extern "C" {
#endif

FAISS_DECLARE_CLASS_INHERITED(IndexHNSW, Index)
FAISS_DECLARE_DESTRUCTOR(IndexHNSW)
FAISS_DECLARE_INDEX_DOWNCAST(IndexHNSW)

FAISS_DECLARE_CLASS_INHERITED(IndexHNSWPQ, IndexHNSW)
FAISS_DECLARE_DESTRUCTOR(IndexHNSWPQ)
FAISS_DECLARE_INDEX_DOWNCAST(IndexHNSWPQ)

int faiss_IndexHNSW_new(FaissIndexHNSW** p_index);
int faiss_IndexHNSW_new_with_options(FaissIndexHNSW** p_index, int d, int M, FaissMetricType metric);

// Adding HNSW's properties for bypassing HNSW's type implementation
void faiss_IndexHNSW_set_efSearch(FaissIndexHNSW* p_index, int efSearch);
void faiss_IndexHNSW_set_efConstruction(FaissIndexHNSW* p_index, int efConstruction);

int faiss_IndexHNSWPQ_new(FaissIndexHNSWPQ** p_index);
int faiss_IndexHNSWPQ_new_with_options(FaissIndexHNSWPQ** p_index, int d, int pq_m, int M);


#ifdef __cplusplus
}
#endif

#endif
