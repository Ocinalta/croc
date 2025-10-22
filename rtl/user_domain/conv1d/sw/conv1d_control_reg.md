<table class="regdef" id="Reg_control">
 <tr>
  <th class="regdef" colspan=5>
   <div>conv1d_control.CONTROL @ 0x0</div>
   <div><p>Accelerator main control and status register</p></div>
   <div>Reset default = 0x0, mask 0x7</div>
  </th>
 </tr>
<tr><td colspan=5><table class="regpic"><tr><td class="bitnum">31</td><td class="bitnum">30</td><td class="bitnum">29</td><td class="bitnum">28</td><td class="bitnum">27</td><td class="bitnum">26</td><td class="bitnum">25</td><td class="bitnum">24</td><td class="bitnum">23</td><td class="bitnum">22</td><td class="bitnum">21</td><td class="bitnum">20</td><td class="bitnum">19</td><td class="bitnum">18</td><td class="bitnum">17</td><td class="bitnum">16</td></tr><tr><td class="unused" colspan=16>&nbsp;</td>
</tr>
<tr><td class="bitnum">15</td><td class="bitnum">14</td><td class="bitnum">13</td><td class="bitnum">12</td><td class="bitnum">11</td><td class="bitnum">10</td><td class="bitnum">9</td><td class="bitnum">8</td><td class="bitnum">7</td><td class="bitnum">6</td><td class="bitnum">5</td><td class="bitnum">4</td><td class="bitnum">3</td><td class="bitnum">2</td><td class="bitnum">1</td><td class="bitnum">0</td></tr><tr><td class="unused" colspan=13>&nbsp;</td>
<td class="fname" colspan=1 style="font-size:27.272727272727273%">LOADED_FLAG</td>
<td class="fname" colspan=1 style="font-size:21.428571428571427%">MCU_USING_SRAM</td>
<td class="fname" colspan=1 style="font-size:60.0%">START</td>
</tr></table></td></tr>
<tr><th width=5%>Bits</th><th width=5%>Type</th><th width=5%>Reset</th><th>Name</th><th>Description</th></tr><tr><td class="regbits">0</td><td class="regperm">rw</td><td class="regrv">0x0</td><td class="regfn">START</td><td class="regde"><p>When this bit is set to 1 by software, the conv1d accelerator should start. Default: 0.</p></td><tr><td class="regbits">1</td><td class="regperm">rw</td><td class="regrv">0x0</td><td class="regfn">MCU_USING_SRAM</td><td class="regde"><p>This bit is set to 1 when the MCU is accessing the SRAM. Default: 0.</p></td><tr><td class="regbits">2</td><td class="regperm">rw</td><td class="regrv">0x0</td><td class="regfn">LOADED_FLAG</td><td class="regde"><p>This bit is set to 1 when the new input/weight has been loaded. Default: 0.</p></td></table>
<br>
<table class="regdef" id="Reg_status1">
 <tr>
  <th class="regdef" colspan=5>
   <div>conv1d_control.STATUS1 @ 0x4</div>
   <div><p>Accelerator status register</p></div>
   <div>Reset default = 0x0, mask 0x7fff3f</div>
  </th>
 </tr>
<tr><td colspan=5><table class="regpic"><tr><td class="bitnum">31</td><td class="bitnum">30</td><td class="bitnum">29</td><td class="bitnum">28</td><td class="bitnum">27</td><td class="bitnum">26</td><td class="bitnum">25</td><td class="bitnum">24</td><td class="bitnum">23</td><td class="bitnum">22</td><td class="bitnum">21</td><td class="bitnum">20</td><td class="bitnum">19</td><td class="bitnum">18</td><td class="bitnum">17</td><td class="bitnum">16</td></tr><tr><td class="unused" colspan=9>&nbsp;</td>
<td class="fname" colspan=5>LEGO_TOWER_DIN</td>
<td class="fname" colspan=2 style="font-size:31.57894736842105%">LEGO_NUMBER_WEIGHTS</td>
</tr>
<tr><td class="bitnum">15</td><td class="bitnum">14</td><td class="bitnum">13</td><td class="bitnum">12</td><td class="bitnum">11</td><td class="bitnum">10</td><td class="bitnum">9</td><td class="bitnum">8</td><td class="bitnum">7</td><td class="bitnum">6</td><td class="bitnum">5</td><td class="bitnum">4</td><td class="bitnum">3</td><td class="bitnum">2</td><td class="bitnum">1</td><td class="bitnum">0</td></tr><tr><td class="fname" colspan=2 style="font-size:40.0%">LEGO_NUMBER_DIN</td>
<td class="fname" colspan=3 style="font-size:56.25%">DATA_NUMBER_SRAM</td>
<td class="fname" colspan=3 style="font-size:50.0%">FILTER_NUMBER_SRAM</td>
<td class="unused" colspan=2>&nbsp;</td>
<td class="fname" colspan=1 style="font-size:27.272727272727273%">DONE_filter</td>
<td class="fname" colspan=1 style="font-size:18.75%">DONE_calculation</td>
<td class="fname" colspan=1 style="font-size:27.272727272727273%">RELOAD_FLAG</td>
<td class="fname" colspan=1 style="font-size:13.636363636363637%">ACCELERATOR_USING_SRAM</td>
<td class="fname" colspan=1 style="font-size:75.0%">DONE</td>
<td class="fname" colspan=1 style="font-size:42.857142857142854%">RUNNING</td>
</tr></table></td></tr>
<tr><th width=5%>Bits</th><th width=5%>Type</th><th width=5%>Reset</th><th>Name</th><th>Description</th></tr><tr><td class="regbits">0</td><td class="regperm">rw</td><td class="regrv">0x0</td><td class="regfn">RUNNING</td><td class="regde"><p>This bit is set to 1 when the accelerator is running. Default: 0.</p></td><tr><td class="regbits">1</td><td class="regperm">rw</td><td class="regrv">0x0</td><td class="regfn">DONE</td><td class="regde"><p>This bit is set to 1 when the accelerator has finished its computation. Default: 0.</p></td><tr><td class="regbits">2</td><td class="regperm">rw</td><td class="regrv">0x0</td><td class="regfn">ACCELERATOR_USING_SRAM</td><td class="regde"><p>This bit is set to 0 when the accelerator is not accessing the SRAM.</p></td><tr><td class="regbits">3</td><td class="regperm">rw</td><td class="regrv">0x0</td><td class="regfn">RELOAD_FLAG</td><td class="regde"><p>This bit is set to 1 when the new input/weight has to be loaded. Default: 0.</p></td><tr><td class="regbits">4</td><td class="regperm">rw</td><td class="regrv">0x0</td><td class="regfn">DONE_calculation</td><td class="regde"><p>This bit is set to 1 when the accelerator has finished the calculation. Default: 0.</p></td><tr><td class="regbits">5</td><td class="regperm">rw</td><td class="regrv">0x0</td><td class="regfn">DONE_filter</td><td class="regde"><p>This bit is set to 1 when the accelerator has finished calculation relative to that filter.</p></td><tr><td class="regbits">7:6</td><td></td><td></td><td></td><td>Reserved</td></tr><tr><td class="regbits">10:8</td><td class="regperm">rw</td><td class="regrv">0x0</td><td class="regfn">FILTER_NUMBER_SRAM</td><td class="regde"><p>The value of these bits represents the number of the filter on which the hardware is working. Its value goes from 0 to 7 (8 filters).</p></td><tr><td class="regbits">13:11</td><td class="regperm">rw</td><td class="regrv">0x0</td><td class="regfn">DATA_NUMBER_SRAM</td><td class="regde"><p>The value of these bits represents the number of iteration for that specific filter we are perfoming. Its value goes from 0 to 6 (we have 7 total execution to complete calculation over 1 filter).</p></td><tr><td class="regbits">15:14</td><td class="regperm">rw</td><td class="regrv">0x0</td><td class="regfn">LEGO_NUMBER_DIN</td><td class="regde"><p>The value of these bits represents the "Lego Block" on which we are working. Its value goes from 0 to 4 (we operate over 4 channels at a time and we totally have 16 channels).</p></td><tr><td class="regbits">17:16</td><td class="regperm">rw</td><td class="regrv">0x0</td><td class="regfn">LEGO_NUMBER_WEIGHTS</td><td class="regde"><p>The value of these bits represents the "Lego Block" on which we are working. Its value goes from 0 to 3 (we operate over 4 channels at a time and we totally have 16 channels).</p></td><tr><td class="regbits">22:18</td><td class="regperm">rw</td><td class="regrv">0x0</td><td class="regfn">LEGO_TOWER_DIN</td><td class="regde"><p>The value of these bits represents the column of input on which we are working. We totally have 18 columns in the SRAM.</p></td></table>
<br>
<table class="regdef" id="Reg_status2">
 <tr>
  <th class="regdef" colspan=5>
   <div>conv1d_control.STATUS2 @ 0x8</div>
   <div><p>Accelerator status register</p></div>
   <div>Reset default = 0x0, mask 0xffffff</div>
  </th>
 </tr>
<tr><td colspan=5><table class="regpic"><tr><td class="bitnum">31</td><td class="bitnum">30</td><td class="bitnum">29</td><td class="bitnum">28</td><td class="bitnum">27</td><td class="bitnum">26</td><td class="bitnum">25</td><td class="bitnum">24</td><td class="bitnum">23</td><td class="bitnum">22</td><td class="bitnum">21</td><td class="bitnum">20</td><td class="bitnum">19</td><td class="bitnum">18</td><td class="bitnum">17</td><td class="bitnum">16</td></tr><tr><td class="unused" colspan=8>&nbsp;</td>
<td class="fname" colspan=8>WEIGHT_ADDRESS</td>
</tr>
<tr><td class="bitnum">15</td><td class="bitnum">14</td><td class="bitnum">13</td><td class="bitnum">12</td><td class="bitnum">11</td><td class="bitnum">10</td><td class="bitnum">9</td><td class="bitnum">8</td><td class="bitnum">7</td><td class="bitnum">6</td><td class="bitnum">5</td><td class="bitnum">4</td><td class="bitnum">3</td><td class="bitnum">2</td><td class="bitnum">1</td><td class="bitnum">0</td></tr><tr><td class="fname" colspan=8>DOUT_ADDRESS</td>
<td class="fname" colspan=8>DIN_ADDRESS</td>
</tr></table></td></tr>
<tr><th width=5%>Bits</th><th width=5%>Type</th><th width=5%>Reset</th><th>Name</th><th>Description</th></tr><tr><td class="regbits">7:0</td><td class="regperm">rw</td><td class="regrv">0x0</td><td class="regfn">DIN_ADDRESS</td><td class="regde"><p>Its value represent the SRAM address of the last INPUT loaded. Default=20.</p></td><tr><td class="regbits">15:8</td><td class="regperm">rw</td><td class="regrv">0x0</td><td class="regfn">DOUT_ADDRESS</td><td class="regde"><p>Its value represent the SRAM address of the last OUTPUT loaded.</p></td><tr><td class="regbits">23:16</td><td class="regperm">rw</td><td class="regrv">0x0</td><td class="regfn">WEIGHT_ADDRESS</td><td class="regde"><p>Its value represent the SRAM address of the last weight loaded. Default=0.</p></td></table>
<br>
