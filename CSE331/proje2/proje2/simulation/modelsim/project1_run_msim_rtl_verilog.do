transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vlog -vlog01compat -work work +incdir+C:/Users/mstrk/Desktop/deneyis/deneme1 {C:/Users/mstrk/Desktop/deneyis/deneme1/and_4bit.v}
vlog -vlog01compat -work work +incdir+C:/Users/mstrk/Desktop/deneyis/deneme1 {C:/Users/mstrk/Desktop/deneyis/deneme1/and_16bit.v}
vlog -vlog01compat -work work +incdir+C:/Users/mstrk/Desktop/deneyis/deneme1 {C:/Users/mstrk/Desktop/deneyis/deneme1/and_32bit.v}
vlog -vlog01compat -work work +incdir+C:/Users/mstrk/Desktop/deneyis/deneme1 {C:/Users/mstrk/Desktop/deneyis/deneme1/nor_4bit.v}
vlog -vlog01compat -work work +incdir+C:/Users/mstrk/Desktop/deneyis/deneme1 {C:/Users/mstrk/Desktop/deneyis/deneme1/nor_16bit.v}
vlog -vlog01compat -work work +incdir+C:/Users/mstrk/Desktop/deneyis/deneme1 {C:/Users/mstrk/Desktop/deneyis/deneme1/nor_32bit.v}
vlog -vlog01compat -work work +incdir+C:/Users/mstrk/Desktop/deneyis/deneme1 {C:/Users/mstrk/Desktop/deneyis/deneme1/or_16bit.v}
vlog -vlog01compat -work work +incdir+C:/Users/mstrk/Desktop/deneyis/deneme1 {C:/Users/mstrk/Desktop/deneyis/deneme1/or_32bit.v}
vlog -vlog01compat -work work +incdir+C:/Users/mstrk/Desktop/deneyis/deneme1 {C:/Users/mstrk/Desktop/deneyis/deneme1/xor_4bit.v}
vlog -vlog01compat -work work +incdir+C:/Users/mstrk/Desktop/deneyis/deneme1 {C:/Users/mstrk/Desktop/deneyis/deneme1/xor_16bit.v}
vlog -vlog01compat -work work +incdir+C:/Users/mstrk/Desktop/deneyis/deneme1 {C:/Users/mstrk/Desktop/deneyis/deneme1/xor_32bit.v}
vlog -vlog01compat -work work +incdir+C:/Users/mstrk/Desktop/deneyis/deneme1 {C:/Users/mstrk/Desktop/deneyis/deneme1/two_bit_comp.v}
vlog -vlog01compat -work work +incdir+C:/Users/mstrk/Desktop/deneyis/deneme1 {C:/Users/mstrk/Desktop/deneyis/deneme1/four_bit_comp.v}
vlog -vlog01compat -work work +incdir+C:/Users/mstrk/Desktop/deneyis/deneme1 {C:/Users/mstrk/Desktop/deneyis/deneme1/eight_bit_comp.v}
vlog -vlog01compat -work work +incdir+C:/Users/mstrk/Desktop/deneyis/deneme1 {C:/Users/mstrk/Desktop/deneyis/deneme1/sixteen_bit_comp.v}
vlog -vlog01compat -work work +incdir+C:/Users/mstrk/Desktop/deneyis/deneme1 {C:/Users/mstrk/Desktop/deneyis/deneme1/thirtytwo_bit_comp.v}
vlog -vlog01compat -work work +incdir+C:/Users/mstrk/Desktop/deneyis/deneme1 {C:/Users/mstrk/Desktop/deneyis/deneme1/carry_look_ahead_4bit.v}
vlog -vlog01compat -work work +incdir+C:/Users/mstrk/Desktop/deneyis/deneme1 {C:/Users/mstrk/Desktop/deneyis/deneme1/carry_look_ahead_32bit.v}
vlog -vlog01compat -work work +incdir+C:/Users/mstrk/Desktop/deneyis/deneme1 {C:/Users/mstrk/Desktop/deneyis/deneme1/subtractor_32bit.v}
vlog -vlog01compat -work work +incdir+C:/Users/mstrk/Desktop/deneyis/deneme1 {C:/Users/mstrk/Desktop/deneyis/deneme1/not_32bit.v}
vlog -vlog01compat -work work +incdir+C:/Users/mstrk/Desktop/deneyis/deneme1 {C:/Users/mstrk/Desktop/deneyis/deneme1/mod.v}
vlog -vlog01compat -work work +incdir+C:/Users/mstrk/Desktop/deneyis/deneme1 {C:/Users/mstrk/Desktop/deneyis/deneme1/mod_fsm_cu.v}
vlog -vlog01compat -work work +incdir+C:/Users/mstrk/Desktop/deneyis/deneme1 {C:/Users/mstrk/Desktop/deneyis/deneme1/mod_fsm_dp.v}
vlog -vlog01compat -work work +incdir+C:/Users/mstrk/Desktop/deneyis/deneme1 {C:/Users/mstrk/Desktop/deneyis/deneme1/alu.v}
vlog -vlog01compat -work work +incdir+C:/Users/mstrk/Desktop/deneyis/deneme1 {C:/Users/mstrk/Desktop/deneyis/deneme1/or_4bit.v}
vlog -vlog01compat -work work +incdir+C:/Users/mstrk/Desktop/deneyis/deneme1 {C:/Users/mstrk/Desktop/deneyis/deneme1/mux_and.v}

vlog -vlog01compat -work work +incdir+C:/Users/mstrk/Desktop/deneyis/deneme1 {C:/Users/mstrk/Desktop/deneyis/deneme1/my_testbench.v}

vsim -t 1ps -L altera_ver -L lpm_ver -L sgate_ver -L altera_mf_ver -L altera_lnsim_ver -L cyclonev_ver -L cyclonev_hssi_ver -L cyclonev_pcie_hip_ver -L rtl_work -L work -voptargs="+acc"  my_testbench

add wave *
view structure
view signals
run -all
