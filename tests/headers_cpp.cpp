#include <stabilora/control/checked_shl_u32.h>
#include <stabilora/control/control_output_clamp_i32.h>
#include <stabilora/control/debounce_counter_bool.h>
#include <stabilora/control/debounce_dual_threshold_i32.h>
#include <stabilora/control/hist_clip_limit_u32.h>
#include <stabilora/control/timeout_backoff_cap_u32.h>

int main(void)
{
    uint32_t value = 0u;
    return stabilora_checked_shl_u32(3u, 2u, &value) && value == 12u ? 0 : 1;
}
