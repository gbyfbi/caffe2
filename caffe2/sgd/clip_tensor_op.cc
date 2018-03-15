#include "caffe2/sgd/clip_tensor_op.h"

namespace caffe2 {

REGISTER_CPU_OPERATOR(ClipTensorByScaling, ClipTensorByScalingOp<CPUContext>);
OPERATOR_SCHEMA(ClipTensorByScaling)
    .NumInputs(2)
    .NumOutputs(1)
    .AllowInplace({{0, 0}})
    .SetDoc(R"DOC(
    Clips the input tensor by scaling based on the input value and the threshold.
    The value is usually the (pre-computed) norm of the tensor. If the value is
    larger than the threshold, scaling would be performed in this way:

          tensor *= (threshold / value).

    This op could be used for gradient clipping.
)DOC")
    .Input(0, "input_tensor", "Tensor of floats to be clipped.")
    .Input(1, "val", "Value to be compared against the threshold")
    .Arg("threshold", "Threshold to determine whether to scale down the tensor")
    .Output(
        0,
        "clipped",
        "Tensor of floats, which is the same size as the input tensor, "
        "representing the clipped tensor.");

SHOULD_NOT_DO_GRADIENT(ClipTensorByScaling);
}; // namespace caffe2
