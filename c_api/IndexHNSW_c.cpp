/**
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

// Copyright 2004-present Facebook. All Rights Reserved.
// -*- c++ -*-

#include "IndexHNSW_c.h"
#include <faiss/IndexHNSW.h>
#include <faiss/MetricType.h>
#include "macros_impl.h"

using faiss::Index;
using faiss::IndexHNSW;
using faiss::IndexHNSWPQ;
using faiss::MetricType;

DEFINE_DESTRUCTOR(IndexHNSW)
DEFINE_INDEX_DOWNCAST(IndexHNSW)

DEFINE_DESTRUCTOR(IndexHNSWPQ)
DEFINE_INDEX_DOWNCAST(IndexHNSWPQ)

int faiss_IndexHNSW_new(FaissIndexHNSW** p_index) {
    try {
        *p_index = reinterpret_cast<FaissIndexHNSW*>(new IndexHNSW());
    }
    CATCH_AND_HANDLE
}

int faiss_IndexHNSW_new_with_options(FaissIndexHNSW** p_index, int d, int M, FaissMetricType metric) {
    try {
        *p_index = reinterpret_cast<FaissIndexHNSW*>(new IndexHNSW(
            d, M, static_cast<MetricType>(metric)
        ));
    }
    CATCH_AND_HANDLE
}

void faiss_IndexHNSW_set_efSearch(FaissIndexHNSW** p_index, int efSearch) {
    reinterpret_cast<IndexHNSW*>(*p_index)->hnsw.efSearch = efSearch;
}

void faiss_IndexHNSW_set_efConstruction(FaissIndexHNSW** p_index, int efConstruction) {
    reinterpret_cast<IndexHNSW*>(*p_index)->hnsw.efConstruction = efConstruction;
}

int faiss_IndexHNSWPQ_new(FaissIndexHNSWPQ** p_index) {
    try {
        *p_index = reinterpret_cast<FaissIndexHNSWPQ*>(new IndexHNSWPQ());
    }
    CATCH_AND_HANDLE
}

int faiss_IndexHNSWPQ_new_with_options(FaissIndexHNSWPQ** p_index, int d, int pq_m, int M) {
    try {
        *p_index = reinterpret_cast<FaissIndexHNSWPQ*>(new IndexHNSWPQ(
            d, pq_m, M
        ));
    }
    CATCH_AND_HANDLE
}
