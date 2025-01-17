// Licensed to the Apache Software Foundation (ASF) under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.

#include "parquet/encryption/openssl_internal.h"

#include <openssl/crypto.h>

#include "parquet/exception.h"

namespace parquet::encryption::openssl {

void EnsureInitialized() {
  // Initialize ciphers and random engines
  if (!OPENSSL_init_crypto(OPENSSL_INIT_ENGINE_ALL_BUILTIN | OPENSSL_INIT_ADD_ALL_CIPHERS,
                           NULL)) {
    throw ParquetException("OpenSSL initialization failed");
  }
}

}  // namespace parquet::encryption::openssl
