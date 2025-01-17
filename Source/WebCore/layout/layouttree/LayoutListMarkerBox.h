/*
 * Copyright (C) 2022 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once

#include "LayoutReplacedBox.h"
#include <wtf/IsoMalloc.h>

namespace WebCore {

namespace Layout {

class ListMarkerBox : public ReplacedBox {
    WTF_MAKE_ISO_ALLOCATED(ListMarkerBox);
public:
    enum class IsImage : uint8_t { No, Yes };
    enum class IsOutside : uint8_t { No, Yes };
    ListMarkerBox(IsImage, IsOutside, RenderStyle&&, std::unique_ptr<RenderStyle>&& firstLineStyle = nullptr);

    bool isImage() const { return m_isImage; }
    bool isOutside() const { return m_isOutside; }

private:
    bool m_isImage { false };
    bool m_isOutside { false };
};

}
}

SPECIALIZE_TYPE_TRAITS_LAYOUT_BOX(ListMarkerBox, isListMarkerBox())

