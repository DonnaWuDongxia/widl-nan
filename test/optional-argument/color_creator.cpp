// To add your copyright and license header

#include "color_creator.h"
#include <string>
#include <sstream>
#include <cmath>

#include "gen/generator_helper.h"

ColorCreator::ColorCreator() {
  // TODO(widl-nan): init your members
}

ColorCreator::~ColorCreator() {
  // TODO(widl-nan): do cleanup if necessary
}

ColorCreator& ColorCreator::operator = (const ColorCreator& rhs) {
  if (&rhs != this) {
    // TODO(widl-nan): copy members from rhs
  }
  return *this;
}

std::string ColorCreator::createColor(const double& r,
    const double& g, const double& b, const double& alpha) {
  // TODO(widl-nan): fill your code here
  std::stringstream ss;
  ss << r << "," << g << "," << b << ",";
  if (std::isnan(alpha)) {
    ss << "Undefined";
  } else {
    ss << alpha;
  }
  return ss.str();
}

std::string ColorCreator::createColor2(const double& r,
    const double& g, const double& b, const double& alpha) {
  // TODO(widl-nan): fill your code here
  std::stringstream ss;
  ss << r << "," << g << "," << b << ",";
  if (std::isnan(alpha)) {
    ss << "Undefined";
  } else {
    ss << alpha;
  }
  return ss.str();
}

std::string ColorCreator::createColor3(const Color& c) {
  std::stringstream ss;
  DictionaryColor cData(c);
  if (cData.has_member_r) {
    ss << cData.member_r;
  } else {
    ss << "Undefined";
  }
  ss << ",";
  if (cData.has_member_g) {
    ss << cData.member_g;
  } else {
    ss << "Undefined";
  }
  ss << ",";
  if (cData.has_member_b) {
    ss << cData.member_b;
  } else {
    ss << "Undefined";
  }
  ss << ",";
  if (cData.has_member_alpha) {
    ss << cData.member_alpha;
  } else {
    ss << "Undefined";
  }
  return ss.str();
}

std::string ColorCreator::primitiveTypeCoverage1(const double& r,
    const double& g, const double& b, const double& alpha) {
  // TODO(widl-nan): fill your code here
  std::stringstream ss;
  ss << r << "," << g << "," << b << ",";
  ss << alpha;
  return ss.str();
}

std::string ColorCreator::primitiveTypeCoverage2(const double& r,
    const double& g, const double& b, const double& alpha) {
  // TODO(widl-nan): fill your code here
  std::stringstream ss;
  ss << r << "," << g << "," << b << ",";
  ss << alpha;
  return ss.str();
}

std::string ColorCreator::primitiveTypeCoverage3(const double& r,
    const double& g, const double& b, const double& alpha) {
  // TODO(widl-nan): fill your code here
  std::stringstream ss;
  ss << r << "," << g << "," << b << ",";
  ss << alpha;
  return ss.str();
}

std::string ColorCreator::primitiveTypeCoverage4(const double& r,
    const double& g, const double& b, const int8_t& alpha) {
  // TODO(widl-nan): fill your code here
  std::stringstream ss;
  ss << r << "," << g << "," << b << ",";
  ss << static_cast<int16_t>(alpha);
  return ss.str();
}

std::string ColorCreator::primitiveTypeCoverage5(const double& r,
    const double& g, const double& b, const uint8_t& alpha) {
  // TODO(widl-nan): fill your code here
  std::stringstream ss;
  ss << r << "," << g << "," << b << ",";
  ss << static_cast<uint16_t>(alpha);
  return ss.str();
}

std::string ColorCreator::primitiveTypeCoverage6(const double& r,
    const double& g, const double& b, const int16_t& alpha) {
  // TODO(widl-nan): fill your code here
  std::stringstream ss;
  ss << r << "," << g << "," << b << ",";
  ss << alpha;
  return ss.str();
}

std::string ColorCreator::primitiveTypeCoverage7(const double& r,
    const double& g, const double& b, const uint16_t& alpha) {
  // TODO(widl-nan): fill your code here
  std::stringstream ss;
  ss << r << "," << g << "," << b << ",";
  ss << alpha;
  return ss.str();
}

std::string ColorCreator::primitiveTypeCoverage8(const double& r,
    const double& g, const double& b, const int32_t& alpha) {
  // TODO(widl-nan): fill your code here
  std::stringstream ss;
  ss << r << "," << g << "," << b << ",";
  ss << alpha;
  return ss.str();
}

std::string ColorCreator::primitiveTypeCoverage9(const double& r,
    const double& g, const double& b, const uint32_t& alpha) {
  // TODO(widl-nan): fill your code here
  std::stringstream ss;
  ss << r << "," << g << "," << b << ",";
  ss << alpha;
  return ss.str();
}

std::string ColorCreator::primitiveTypeCoverage10(const double& r,
    const double& g, const double& b, const int64_t& alpha) {
  // TODO(widl-nan): fill your code here
  std::stringstream ss;
  ss << r << "," << g << "," << b << ",";
  ss << alpha;
  return ss.str();
}

std::string ColorCreator::primitiveTypeCoverage11(const double& r,
    const double& g, const double& b, const uint64_t& alpha) {
  // TODO(widl-nan): fill your code here
  std::stringstream ss;
  ss << r << "," << g << "," << b << ",";
  ss << alpha;
  return ss.str();
}

std::string ColorCreator::primitiveTypeCoverage12(const double& r,
    const double& g, const double& b, const std::string& alpha) {
  // TODO(widl-nan): fill your code here
  std::stringstream ss;
  ss << r << "," << g << "," << b << ",";
  ss << alpha;
  return ss.str();
}

std::string ColorCreator::primitiveTypeCoverage13(const double& r,
    const double& g, const double& b, const bool& alpha) {
  // TODO(widl-nan): fill your code here
  std::stringstream ss;
  ss << r << "," << g << "," << b << ",";
  if (alpha == true) {
    ss << "true";
  } else if (alpha == false) {
    ss << "false";
  } else {
    ss << "INVALID_BOOL_VALUE";
  }
  return ss.str();
}

v8::Handle<v8::Promise> ColorCreator::promiseReturnValue(const Color& c) {
  using ResolverPersistent = Nan::Persistent<v8::Promise::Resolver>;

  auto period = 3000;  // In ms
  auto resolver = v8::Promise::Resolver::New(v8::Isolate::GetCurrent());
  auto persistent = new ResolverPersistent(resolver);

  auto cData = new DictionaryColor(c);

  struct ColorData {
    DictionaryColor* cData;
    ResolverPersistent* persistent;
  };

  uv_timer_t* handle = new uv_timer_t;
  handle->data = new ColorData{cData, persistent};
  uv_timer_init(uv_default_loop(), handle);

  // use capture-less lambda for c-callback
  auto timercb = [](uv_timer_t* handle) -> void {
    Nan::HandleScope scope;

    auto persistent = static_cast<ColorData*>(handle->data)->persistent;
    auto cData = static_cast<ColorData*>(handle->data)->cData;
    delete static_cast<ColorData*>(handle->data);

    uv_timer_stop(handle);
    uv_close(reinterpret_cast<uv_handle_t*>(handle),
             [](uv_handle_t* handle) -> void {delete handle;});

    std::stringstream ss;
    if (cData->has_member_r) {
      ss << cData->member_r;
    } else {
      ss << "Undefined";
    }
    ss << ",";
    if (cData->has_member_g) {
      ss << cData->member_g;
    } else {
      ss << "Undefined";
    }
    ss << ",";
    if (cData->has_member_b) {
      ss << cData->member_b;
    } else {
      ss << "Undefined";
    }
    ss << ",";
    if (cData->has_member_alpha) {
      ss << cData->member_alpha;
    } else {
      ss << "Undefined";
    }

    auto resolver = Nan::New(*persistent);
    resolver->Resolve(Nan::New(ss.str()).ToLocalChecked());

    persistent->Reset();
    delete persistent;
  };
  uv_timer_start(handle, timercb, period, 0);

  return resolver->GetPromise();
  /*
  PromiseHelper promise;
  std::stringstream ss;
  DictionaryColor cData(c);

  if (cData.has_member_r) {
    ss << cData.member_r;
  } else {
    ss << "Undefined";
  }
  ss << ",";
  if (cData.has_member_g) {
    ss << cData.member_g;
  } else {
    ss << "Undefined";
  }
  ss << ",";
  if (cData.has_member_b) {
    ss << cData.member_b;
  } else {
    ss << "Undefined";
  }
  ss << ",";
  if (cData.has_member_alpha) {
    ss << cData.member_alpha;
  } else {
    ss << "Undefined";
  }
  promise.ResolvePromise(ss.str());
  return promise.CreatePromise();
  */
}
