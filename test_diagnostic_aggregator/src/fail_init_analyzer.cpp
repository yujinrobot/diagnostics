/*********************************************************************
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2010, Willow Garage, Inc.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of the Willow Garage nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *********************************************************************/

/*!
 * \author Kevin Watts 
 */

#include "test_diagnostic_aggregator/fail_init_analyzer.h"

using namespace diagnostic_aggregator;
using namespace test_diagnostic_aggregator;
using namespace std;

PLUGINLIB_DECLARE_CLASS(test_diagnostic_aggregator,
                        FailInitAnalyzer,
                        test_diagnostic_aggregator::FailInitAnalyzer,
                        diagnostic_aggregator::Analyzer)

FailInitAnalyzer::FailInitAnalyzer() :
  path_(""),
  nice_name_("")
{ }

FailInitAnalyzer::~FailInitAnalyzer() { }


bool FailInitAnalyzer::init(const string base_name, const ros::NodeHandle &n)
{ 
  nice_name_ = "Fail Init";

  // path_ = BASE_NAME/Motors
  if (base_name == "/")
    path_ = base_name + nice_name_;
  else
    path_ = base_name + "/" + nice_name_;

  ROS_INFO("FailInitAnalyzer is returning false. Fails to initialize on purpose");
  return false;
}


bool FailInitAnalyzer::match(const std::string name)
{
  return false;
}

bool FailInitAnalyzer::analyze(const boost::shared_ptr<StatusItem> item)
{
  return false;
}

vector<boost::shared_ptr<diagnostic_msgs::DiagnosticStatus> > FailInitAnalyzer::report()
{
  vector<boost::shared_ptr<diagnostic_msgs::DiagnosticStatus> > output;

  return output;
}
