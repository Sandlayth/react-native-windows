// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#pragma once

#include "FrameworkElementViewManager.h"

namespace react { namespace uwp {

class VirtualTextViewManager : public ViewManagerBase
{
  using Super = ViewManagerBase;
public:
  VirtualTextViewManager(const std::shared_ptr<IReactInstance>& reactInstance);

  const char* GetName() const override;
  void UpdateProperties(ShadowNodeBase* nodeToUpdate, XamlView viewToUpdate, folly::dynamic reactDiffMap) override;

  void AddView(XamlView parent, XamlView child, int64_t index) override;
  XamlView GetChildAt(XamlView parent, int64_t index) override;
  int64_t GetChildCount(XamlView parent) override;
  void RemoveAllChildren(XamlView parent) override;
  void RemoveChildAt(XamlView parent, int64_t index) override;

  bool RequiresYogaNode() const override;

protected:
  XamlView CreateViewCore(int64_t tag) override;
};

} }
